#include <iostream>
using namespace std;

int N;
char board[55][55];
int maxValue = 1;

int findCandy(int y, int x, char color) {
    int garo = 0;
    int sero = 0;
    int maxNum = 1;

    for (int i = 0; i < N; i++) {
        int num = 1;
        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                num++;
            } else {
                garo = max(garo, num);
                num = 1;
            }
        }
        garo = max(garo, num);
    }

    for (int i = 0; i < N; i++) {
        int num = 1;
        for (int j = 0; j < N - 1; j++) {
            if (board[j][i] == board[j + 1][i]) {
                num++;
            } else {
                sero = max(sero, num);
                num = 1;
            }
        }
        sero = max(sero, num);
    }

    maxNum = max(maxNum, garo);
    maxNum = max(maxNum, sero);

    return maxNum;
}

void changeDown(int y, int x) {
    int ny = y + 1;
    if (ny >= N) {
        return;
    }
    if (board[y][x] == board[ny][x]) {
        return;
    }
    swap(board[y][x], board[ny][x]);

    int num1 = findCandy(y, x, board[y][x]);
    int num2 = findCandy(ny, x, board[ny][x]);
    maxValue = max(maxValue, num1);
    maxValue = max(maxValue, num2);

    swap(board[y][x], board[ny][x]);
}

void changeRight(int y, int x) {
    int nx = x + 1;

    if (nx >= N) {
        return;
    }
    if (board[y][nx] == board[y][x]) {
        return;
    }

    swap(board[y][x], board[y][nx]);

    int num1 = findCandy(y, x, board[y][x]);
    int num2 = findCandy(y, nx, board[y][nx]);

    if (maxValue < num1) {
        maxValue = num1;
    }

    if (maxValue < num2) {
        maxValue = num2;
    }

    swap(board[y][x], board[y][nx]);
}

void changeCandy(int y, int x) {
    changeDown(y, x);
    changeRight(y, x);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            changeCandy(i, j);
        }
    }

    cout << maxValue << '\n';
    return 0;
}