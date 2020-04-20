# 백준 16939 - 2×2×2 큐브
![](16939.JPG)

## 문제 풀이
큐빙 문제를 풀었다면 쉽게 풀 수 있는거 같다. 배열의 이동 연산이 관건인 문제이다.

## 전체 소스 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int cube[25];
int blocks[6][8] = {
    // 정면 왼쪽
    {1, 3, 5, 7, 9, 11, 24, 22},
    // 정면 오른쪽
    {2, 4, 6, 8, 10, 12, 23, 21},
    // 정면 첫번째
    {13, 14, 5, 6, 17, 18, 21, 22},
    // 정면 두번째
    {15, 16, 7, 8, 19, 20, 23, 24},
    // 측면 첫번째
    {3, 4, 17, 19, 10, 9, 16, 14},
    // 측면 두번째
    {1, 2, 18, 20, 12, 11, 15, 13},
};
bool isPass = false;

// 정면 왼쪽
void moveLeftUpDown() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[0][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[0][i];

        cube[index] = temp[i];
    }
}
// 정면 오른쪽
void moveRightUpDown() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[1][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[1][i];

        cube[index] = temp[i];
    }
}
// 정면 첫번째
void moveFirstRightLeft() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[2][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[2][i];

        cube[index] = temp[i];
    }
}
// 정면 두번째
void moveSecondRightLeft() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[3][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[3][i];

        cube[index] = temp[i];
    }
}
// 측면 1
void moveFirstUpDown() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[4][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[4][i];

        cube[index] = temp[i];
    }
}
// 측면 2
void moveSecondUpDown() {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[5][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[5][i];

        cube[index] = temp[i];
    }
}

bool isAllSame() {
    int color = cube[1];
    for (int i = 1; i <= 4; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    color = cube[5];
    for (int i = 5; i <= 8; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    color = cube[9];
    for (int i = 9; i <= 12; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    color = cube[13];
    for (int i = 13; i <= 16; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    color = cube[17];
    for (int i = 17; i <= 20; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    color = cube[21];
    for (int i = 21; i <= 24; i++) {
        if (color != cube[i]) {
            return false;
        }
    }

    isPass = true;
    return true;
}

int move() {
    // 정면 왼쪽 위
    moveLeftUpDown();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveLeftUpDown();
    }

    // 정면 왼쪽 아래
    for (int i = 0; i < 3; i++) {
        moveLeftUpDown();
    }

    if (isAllSame()) {
        return 1;
    }
    moveLeftUpDown();

    // 정면 오른쪽 위
    moveRightUpDown();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveRightUpDown();
    }

    // 정면 오른쪽 아래
    for (int i = 0; i < 3; i++) {
        moveRightUpDown();
    }
    if (isAllSame()) {
        return 1;
    }
    moveRightUpDown();

    // 정면 첫번째 오른쪽
    moveFirstRightLeft();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveFirstRightLeft();
    }

    // 정면 첫번째 왼쪽
    for (int i = 0; i < 3; i++) {
        moveFirstRightLeft();
    }
    if (isAllSame()) {
        return 1;
    }
    moveFirstRightLeft();

    // 정면 두번째 오른쪽
    moveSecondRightLeft();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveSecondRightLeft();
    }

    // 정면 두번째 왼쪽
    for (int i = 0; i < 3; i++) {
        moveSecondRightLeft();
    }
    if (isAllSame()) {
        return 1;
    }
    moveSecondRightLeft();

    // 측면 첫번째 위
    moveFirstUpDown();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveFirstUpDown();
    }

    // 측면 첫번째 아래
    for (int i = 0; i < 3; i++) {
        moveFirstUpDown();
    }
    if (isAllSame()) {
        return 1;
    }
    moveFirstUpDown();

    // 측면 두번째 위
    moveSecondUpDown();
    if (isAllSame()) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        moveSecondUpDown();
    }

    // 측면 두번째 아래
    for (int i = 0; i < 3; i++) {
        moveSecondUpDown();
    }
    if (isAllSame()) {
        return 1;
    }
    moveSecondUpDown();

    return 0;
}

int main(void) {
    int n = 24;

    for (int i = 1; i <= n; i++) {
        cin >> cube[i];
    }

    cout << move() << '\n';
}
```