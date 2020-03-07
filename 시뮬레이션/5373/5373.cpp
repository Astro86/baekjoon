#include <iostream>
using namespace std;

int testCase;
int n;
char cube[12][9];

void initCube() {
    // 오렌지 뒤
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[i][3 + j] = 'o';
        }
    }

    // 초록색 왼
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[3 + i][j] = 'g';
        }
    }

    // 흰색 위
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[3 + i][3 + j] = 'w';
        }
    }

    // 빨강 앞
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[6 + i][3 + j] = 'r';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[9 + i][3 + j] = 'y';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[3 + i][6 + j] = 'b';
        }
    }
}

void moveRight(int y, int x) {
    int temp[9];
    temp[0] = cube[y][x];
    temp[1] = cube[y][x + 1];
    temp[2] = cube[y][x + 2];
    temp[3] = cube[y + 1][x];
    temp[4] = cube[y + 1][x + 1];
    temp[5] = cube[y + 1][x + 2];
    temp[6] = cube[y + 2][x];
    temp[7] = cube[y + 2][x + 1];
    temp[8] = cube[y + 2][x + 2];

    cube[y][x] = temp[6];
    cube[y][x + 1] = temp[3];
    cube[y][x + 2] = temp[0];

    cube[y][x + 2] = temp[0];
    cube[y + 1][x + 2] = temp[1];
    cube[y + 2][x + 2] = temp[2];

    cube[y + 2][x + 2] = temp[2];
    cube[y + 2][x + 1] = temp[5];
    cube[y + 2][x] = temp[8];

    cube[y + 2][x] = temp[8];
    cube[y + 1][x] = temp[7];
    cube[y][x] = temp[6];
}

void moveLeft(int y, int x) {
    int temp[9];
    temp[0] = cube[y][x];
    temp[1] = cube[y][x + 1];
    temp[2] = cube[y][x + 2];
    temp[3] = cube[y + 1][x];
    temp[4] = cube[y + 1][x + 1];
    temp[5] = cube[y + 1][x + 2];
    temp[6] = cube[y + 2][x];
    temp[7] = cube[y + 2][x + 1];
    temp[8] = cube[y + 2][x + 2];

    cube[y][x] = temp[2];
    cube[y][x + 1] = temp[5];
    cube[y][x + 2] = temp[8];

    cube[y][x + 2] = temp[8];
    cube[y + 1][x + 2] = temp[7];
    cube[y + 2][x + 2] = temp[6];

    cube[y + 2][x + 2] = temp[6];
    cube[y + 2][x + 1] = temp[3];
    cube[y + 2][x] = temp[0];

    cube[y + 2][x] = temp[0];
    cube[y + 1][x] = temp[1];
    cube[y][x] = temp[2];
}

void moveUpRight() {
    char temp23, temp24, temp25,
        temp32, temp42, temp52,
        temp36, temp46, temp56,
        temp63, temp64, temp65;

    temp23 = cube[2][3];
    temp24 = cube[2][4];
    temp25 = cube[2][5];
    temp36 = cube[3][6];
    temp46 = cube[4][6];
    temp56 = cube[5][6];
    temp63 = cube[6][3];
    temp64 = cube[6][4];
    temp65 = cube[6][5];
    temp32 = cube[3][2];
    temp42 = cube[4][2];
    temp52 = cube[5][2];

    cube[2][3] = temp52;
    cube[2][4] = temp42;
    cube[2][5] = temp32;

    cube[3][6] = temp23;
    cube[4][6] = temp24;
    cube[5][6] = temp25;

    cube[6][5] = temp36;
    cube[6][4] = temp46;
    cube[6][3] = temp56;

    cube[5][2] = temp65;
    cube[4][2] = temp64;
    cube[3][2] = temp63;
}

void moveUpLeft() {
    char temp23, temp24, temp25,
        temp32, temp42, temp52,
        temp36, temp46, temp56,
        temp63, temp64, temp65;

    temp23 = cube[2][3];
    temp24 = cube[2][4];
    temp25 = cube[2][5];
    temp32 = cube[3][2];
    temp42 = cube[4][2];
    temp52 = cube[5][2];
    temp36 = cube[3][6];
    temp46 = cube[4][6];
    temp56 = cube[5][6];
    temp63 = cube[6][3];
    temp64 = cube[6][4];
    temp65 = cube[6][5];

    cube[2][3] = temp36;
    cube[2][4] = temp46;
    cube[2][5] = temp56;

    cube[3][6] = temp65;
    cube[4][6] = temp64;
    cube[5][6] = temp63;

    cube[6][5] = temp52;
    cube[6][4] = temp42;
    cube[6][3] = temp32;

    cube[5][2] = temp23;
    cube[4][2] = temp24;
    cube[3][2] = temp25;
}

void moveLeftRight() {
    for (int i = 0; i < 3; i++) {
        int temp = cube[11][3];
        for (int i = 10; i >= 0; i--) {
            cube[i + 1][3] = cube[i][3];
        }
        cube[0][3] = temp;
    }
}
void moveLeftLeft() {
    for (int i = 0; i < 3; i++) {
        int temp = cube[0][3];
        for (int i = 0; i < 11; i++) {
            cube[i][3] = cube[i + 1][3];
        }
        cube[11][3] = temp;
    }
}

void moveRightRight() {
    for (int i = 0; i < 3; i++) {
        int temp = cube[0][5];
        for (int i = 0; i < 11; i++) {
            cube[i][5] = cube[i + 1][5];
        }
        cube[11][5] = temp;
    }
}

void moveRightLeft() {
    for (int i = 0; i < 3; i++) {
        int temp = cube[11][5];
        for (int i = 10; i >= 0; i--) {
            cube[i + 1][5] = cube[i][5];
        }
        cube[0][5] = temp;
    }
}
void moveFrontRigth() {
    int temp1, temp2, temp3;
    temp1 = cube[5][6];
    temp2 = cube[5][7];
    temp3 = cube[5][8];

    for (int i = 3; i >= 0; i -= 3) {
        cube[5][i + 3] = cube[5][i];
        cube[5][i + 4] = cube[5][i + 1];
        cube[5][i + 5] = cube[5][i + 2];
    }

    cube[5][2] = cube[9][3];
    cube[5][1] = cube[9][4];
    cube[5][0] = cube[9][5];
    cube[9][3] = temp3;
    cube[9][4] = temp2;
    cube[9][5] = temp1;
}
void moveFrontLeft() {
    int temp1, temp2, temp3;
    temp1 = cube[5][0];
    temp2 = cube[5][1];
    temp3 = cube[5][2];

    for (int i = 0; i < 6; i += 3) {
        cube[5][i] = cube[5][i + 3];
        cube[5][i + 1] = cube[5][i + 4];
        cube[5][i + 2] = cube[5][i + 5];
    }
    cube[5][6] = cube[9][5];
    cube[5][7] = cube[9][4];
    cube[5][8] = cube[9][3];
    cube[9][3] = temp3;
    cube[9][4] = temp2;
    cube[9][5] = temp1;
}

void moveBackRight() {
    int temp1, temp2, temp3;
    temp1 = cube[3][0];
    temp2 = cube[3][1];
    temp3 = cube[3][2];

    for (int i = 0; i < 6; i += 3) {
        cube[3][i] = cube[3][i + 3];
        cube[3][i + 1] = cube[3][i + 4];
        cube[3][i + 2] = cube[3][i + 5];
    }
    cube[3][6] = cube[11][5];
    cube[3][7] = cube[11][4];
    cube[3][8] = cube[11][3];
    cube[11][3] = temp3;
    cube[11][4] = temp2;
    cube[11][5] = temp1;
}

void moveBackLeft() {
    int temp1, temp2, temp3;
    temp1 = cube[3][6];
    temp2 = cube[3][7];
    temp3 = cube[3][8];

    for (int i = 3; i >= 0; i -= 3) {
        cube[3][i + 3] = cube[3][i];
        cube[3][i + 4] = cube[3][i + 1];
        cube[3][i + 5] = cube[3][i + 2];
    }

    cube[3][2] = cube[11][3];
    cube[3][1] = cube[11][4];
    cube[3][0] = cube[11][5];
    cube[11][3] = temp3;
    cube[11][4] = temp2;
    cube[11][5] = temp1;
}

void moveDownRight() {
    int t83, t84, t85,
        t58, t48, t38,
        t05, t04, t03,
        t30, t40, t50;

    t83 = cube[8][3];
    t84 = cube[8][4];
    t85 = cube[8][5];

    t30 = cube[3][0];
    t40 = cube[4][0];
    t50 = cube[5][0];

    t03 = cube[0][3];
    t04 = cube[0][4];
    t05 = cube[0][5];

    t58 = cube[5][8];
    t48 = cube[4][8];
    t38 = cube[3][8];

    cube[8][3] = t30;
    cube[8][4] = t40;
    cube[8][5] = t50;

    cube[5][8] = t83;
    cube[4][8] = t84;
    cube[3][8] = t85;

    cube[0][3] = t38;
    cube[0][4] = t48;
    cube[0][5] = t58;

    cube[3][0] = t05;
    cube[4][0] = t04;
    cube[5][0] = t03;
}

void moveDownLeft() {
    int t83, t84, t85,
        t58, t48, t38,
        t05, t04, t03,
        t30, t40, t50;

    t83 = cube[8][3];
    t84 = cube[8][4];
    t85 = cube[8][5];

    t30 = cube[3][0];
    t40 = cube[4][0];
    t50 = cube[5][0];

    t03 = cube[0][3];
    t04 = cube[0][4];
    t05 = cube[0][5];

    t58 = cube[5][8];
    t48 = cube[4][8];
    t38 = cube[3][8];

    cube[3][0] = t83;
    cube[4][0] = t84;
    cube[5][0] = t85;

    cube[8][3] = t58;
    cube[8][4] = t48;
    cube[8][5] = t38;

    cube[5][8] = t05;
    cube[4][8] = t04;
    cube[3][8] = t03;

    cube[0][5] = t50;
    cube[0][4] = t40;
    cube[0][3] = t30;
}

int main(void) {
    cin >> testCase;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 9; j++) {
            cube[i][j] = ' ';
        }
    }

    while (testCase--) {
        initCube();
        cin >> n;

        while (n--) {
            string s;
            cin >> s;
            char command;
            char dir;

            command = s[0];
            dir = s[1];

            if (command == 'U') {
                if (dir == '+') {
                    moveUpRight();
                    moveRight(3, 3);
                } else {
                    moveLeft(3, 3);
                    moveUpLeft();
                }

            } else if (command == 'D') {
                if (dir == '+') {
                    moveRight(9, 3);
                    moveDownRight();
                } else {
                    moveLeft(9, 3);
                    moveDownLeft();
                }

            } else if (command == 'F') {
                if (dir == '+') {
                    moveRight(6, 3);
                    moveFrontRigth();
                } else {
                    moveLeft(6, 3);
                    moveFrontLeft();
                }
            } else if (command == 'B') {
                if (dir == '+') {
                    moveRight(0, 3);
                    moveBackRight();
                } else {
                    moveLeft(0, 3);
                    moveBackLeft();
                }

            } else if (command == 'L') {
                if (dir == '+') {
                    moveRight(3, 0);
                    moveLeftRight();
                } else {
                    moveLeft(3, 0);
                    moveLeftLeft();
                }

            } else if (command == 'R') {
                if (dir == '+') {
                    moveRight(3, 6);
                    moveRightRight();
                } else {
                    moveLeft(3, 6);
                    moveRightLeft();
                }
            }

            // cout << command << dir << endl;
            // for (int i = 0; i < 12; i++) {
            //     for (int j = 0; j < 9; j++) {
            //         cout << cube[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[i + 3][j + 3];
            }
            cout << endl;
        }
    }
}