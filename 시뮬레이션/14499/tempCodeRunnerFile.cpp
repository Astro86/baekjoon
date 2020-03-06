#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int map[22][22];
int cube[4][3];
vector<int> command;

void moveUp()
{
    if (y - 1 >= 0) {
        y -= 1;

        int temp01, temp11, temp21, temp31;
        temp01 = cube[0][1];
        temp11 = cube[1][1];
        temp21 = cube[2][1];
        temp31 = cube[3][1];

        cube[0][1] = temp11;
        cube[1][1] = temp21;
        cube[2][1] = temp31;
        cube[3][1] = temp01;

        int next = map[y][x];
        if (next == 0) {
            map[y][x] = cube[3][1];
        } else {
            cube[3][1] = map[y][x];
            map[y][x] = 0;
        }

        cout << cube[1][1] << '\n';
    } else {
        return;
    }

    // cout << endl;
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << cube[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void moveDown()
{
    if (y + 1 < n) {
        y += 1;

        int temp01, temp11, temp21, temp31;
        temp01 = cube[0][1];
        temp11 = cube[1][1];
        temp21 = cube[2][1];
        temp31 = cube[3][1];

        cube[1][1] = temp01;
        cube[2][1] = temp11;
        cube[3][1] = temp21;
        cube[0][1] = temp31;

        int next = map[y][x];
        if (next == 0) {
            map[y][x] = cube[3][1];
        } else {
            cube[3][1] = map[y][x];
            map[y][x] = 0;
        }
        cout << cube[1][1] << '\n';

    } else {
        return;
    }
}

void moveRight()
{
    if (x + 1 < m) {
        x += 1;

        int temp11, temp12, temp31, temp10;
        temp11 = cube[1][1];
        temp12 = cube[1][2];
        temp31 = cube[3][1];
        temp10 = cube[1][0];

        cube[1][1] = temp10;
        cube[1][2] = temp11;
        cube[3][1] = temp12;
        cube[1][0] = temp31;

        int next = map[y][x];
        if (next == 0) {
            map[y][x] = cube[3][1];
        } else {
            cube[3][1] = map[y][x];
            map[y][x] = 0;
        }
        cout << cube[1][1] << '\n';

    } else {
        return;
    }
}

void moveLeft()
{
    if (x - 1 >= 0) {
        x -= 1;

        int temp11, temp12, temp31, temp10;
        temp11 = cube[1][1];
        temp12 = cube[1][2];
        temp31 = cube[3][1];
        temp10 = cube[1][0];

        cube[1][0] = temp11;
        cube[1][1] = temp12;
        cube[1][2] = temp31;
        cube[3][1] = temp10;

        int next = map[y][x];
        if (next == 0) {
            map[y][x] = cube[3][1];
        } else {
            cube[3][1] = map[y][x];
            map[y][x] = 0;
        }
        cout << cube[1][1] << '\n';
    } else {
        return;
    }
}

void moveCube()
{
    int commandNum = command.size();
    for (int i = 0; i < commandNum; i++) {
        int cntCommand = command[i];

        if (cntCommand == 1) {
            moveRight();
        } else if (cntCommand == 2) {
            moveLeft();
        } else if (cntCommand == 3) {
            moveUp();
        } else if (cntCommand == 4) {
            moveDown();
        }
    }
}

int main(void)
{
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int temp = 0;
        cin >> temp;
        command.push_back(temp);
    }
    moveCube();

    return 0;
}