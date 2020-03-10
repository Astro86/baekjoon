#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int map[10][10];
bool domino[10][10];
int total = 0;
int result[10][10];
vector<pair<int, int>> points;

void chooseDomino(int num1, int num2) {
    domino[num1][num2] = true;
    domino[num2][num1] = true;
}

void releaseDomino(int num1, int num2) {
    domino[num1][num2] = false;
    domino[num2][num1] = false;
}

vector<int> findNumber(int y, int x) {
    vector<bool> check(10, false);
    vector<int> numbers;

    // 가로 확인
    for (int i = 1; i <= 9; i++) {
        if (map[y][i] != 0) {
            check[map[y][i]] = true;
        }
    }

    // 세로 확인
    for (int i = 1; i <= 9; i++) {
        if (map[i][x] != 0) {
            check[map[i][x]] = true;
        }
    }

    // 해당 되는 칸을 확인
    int y_1 = y - 1;
    int x_1 = x - 1;
    int rangeY = (y_1 / 3) * 3 + 1;
    int rangeX = (x_1 / 3) * 3 + 1;
    for (int i = rangeY; i < rangeY + 3; i++) {
        for (int j = rangeX; j < rangeX + 3; j++) {
            check[map[i][j]] = true;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (check[i] == false) {
            numbers.push_back(i);
        }
    }

    return numbers;
}

void sudoku(int index) {
    if (index == points.size()) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                result[i][j] = map[i][j];
            }
        }
        return;
    }

    int y, x;
    y = points[index].first;
    x = points[index].second;

    if (map[y][x] != 0) {
        sudoku(index + 1);
    } else {
        vector<int> group1 = findNumber(y, x);
        for (int i = 0; i < group1.size(); i++) {
            int number1 = group1[i];
            map[y][x] = group1[i];

            // 가로로 놓기
            if (x + 1 <= 9 && map[y][x + 1] == 0) {
                vector<int> group2 = findNumber(y, x + 1);

                for (int j = 0; j < group2.size(); j++) {
                    int number2 = group2[j];

                    if (domino[number1][number2] == false) {
                        chooseDomino(number1, number2);
                        map[y][x + 1] = number2;
                        sudoku(index + 1);
                        map[y][x + 1] = 0;
                        releaseDomino(number1, number2);
                    }
                }
            }

            if (y + 1 <= 9 && map[y + 1][x] == 0) {
                vector<int> group3 = findNumber(y + 1, x);

                for (int j = 0; j < group3.size(); j++) {
                    int number2 = group3[j];

                    if (domino[number1][number2] == false) {
                        chooseDomino(number1, number2);
                        map[y + 1][x] = number2;
                        sudoku(index + 1);
                        map[y + 1][x] = 0;
                        releaseDomino(number1, number2);
                    }
                }
            }
            map[y][x] = 0;
        }
    }
}

int main(void) {
    while (true) {
        total++;
        cin >> N;

        if (N == 0) {
            break;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = 0;
                domino[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            int value1;
            string point1;
            int value2;
            string point2;

            cin >> value1 >> point1 >> value2 >> point2;
            map[point1[0] - 'A' + 1][point1[1] - '0'] = value1;
            map[point2[0] - 'A' + 1][point2[1] - '0'] = value2;
            domino[value1][value2] = true;
            domino[value2][value1] = true;
        }

        for (int i = 0; i < 9; i++) {
            string point;
            cin >> point;
            map[point[0] - 'A' + 1][point[1] - '0'] = i + 1;
        }

        vector<pair<int, int>> temp;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (map[i][j] == 0) {
                    temp.push_back({i, j});
                }
            }
        }
        points = temp;
        sudoku(0);

        cout << "Puzzle " << total << '\n';
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << result[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
