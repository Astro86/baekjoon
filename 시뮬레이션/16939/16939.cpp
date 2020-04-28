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

void moveCube(int dir) {
    int temp[8];
    for (int i = 0; i < 8; i++) {
        int index = blocks[dir][(i + 2) % 8];

        temp[i] = cube[index];
    }

    for (int i = 0; i < 8; i++) {
        int index = blocks[dir][i];

        cube[index] = temp[i];
    }
}

bool isAllSame() {
    for (int i = 0; i < 6; i++) {
        int start = (i * 4) + 1;

        int color = cube[start];
        for (int j = start; j < start + 4; j++) {
            if (color != cube[j]) {
                return false;
            }
        }
    }
    return true;
}

int move() {
    // 정면 왼쪽 위
    for (int i = 0; i < 6; i++) {
        moveCube(i);
        if (isAllSame()) {
            return 1;
        }
        for (int j = 0; j < 2; j++) {
            moveCube(i);
        }
        if (isAllSame()) {
            return 1;
        }
        moveCube(i);
    }
    return 0;
}

int main(void) {
    int n = 24;

    for (int i = 1; i <= n; i++) {
        cin >> cube[i];
    }

    cout << move() << '\n';
}