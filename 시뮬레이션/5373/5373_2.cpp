#include <iostream>
using namespace std;

/*
 0  1  2  3  4  5  6  7  8  => w
 9 10 11 12 13 14 15 16 17  => y
18 19 20 21 22 23 24 25 26  => r
27 28 29 30 31 32 33 34 35  => o
36 37 38 39 40 41 42 43 44  => g
45 46 47 48 49 50 51 52 53  => b
*/

/*            U
          0  1  2
          3  4  5
          6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
        -----------
          9  10 11
          12 13 14
          15 16 17
          D
*/

/*
   U (0)     D (1)      F (2)      B (3)      L (4)      R (5)
 0  1  2 |  9 10 11 | 18 19 20 | 27 28 29 | 36 37 38 | 45 46 47  
 3  4  5 | 12 13 14 | 21 22 23 | 30 31 32 | 39 40 41 | 48 49 50
 6  7  8 | 15 16 17 | 24 25 26 | 33 34 35 | 42 43 44 | 51 52 53
*/

enum FACE {
    U,
    D,
    F,
    B,
    L,
    R,
    SIZE
};

char init[7] = "wyrogb";
char arr[55];
int cube[SIZE][3][3];
char temp[3][3];
int conv[256];

int rot[6][12] = {
    {36, 37, 38, 18, 19, 20, 45, 46, 47, 27, 28, 29},
    {33, 34, 35, 51, 52, 53, 24, 25, 26, 42, 43, 44},
    {6, 7, 8, 44, 41, 38, 11, 10, 9, 45, 48, 51},
    {2, 1, 0, 53, 50, 47, 15, 16, 17, 36, 39, 42},
    {0, 3, 6, 35, 32, 29, 9, 12, 15, 18, 21, 24},
    {8, 5, 2, 26, 23, 20, 17, 14, 11, 27, 30, 33}};

void rotate(FACE f, int cnt) {
    char que[12];

    while (cnt--) {
        for (int i = 0; i < 12; i++) {
            int Index = rot[f][i];

            que[i] = arr[Index];
        }

        for (int i = 0; i < 12; i++) {
            int Index = rot[f][i];

            arr[Index] = que[(i + 3) % 12];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int Index = cube[f][i][j];

                temp[j][2 - i] = arr[Index];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int Index = cube[f][i][j];

                arr[Index] = temp[i][j];
            }
        }
    }
}

int main(void) {
    conv['-'] = 3;
    conv['+'] = 1;
    conv['U'] = U;
    conv['D'] = D;
    conv['F'] = F;
    conv['B'] = B;
    conv['L'] = L;
    conv['R'] = R;

    /*       U
          0  1  2
          3  4  5
          6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
        -----------
          9  10 11
          12 13 14
          15 16 17
             D
*/

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = i * 9 + j * 3 + k;
            }
        }
    }

    int n, m;
    char comm[3];

    cin >> n;

    while (n--) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                arr[i * 9 + j] = init[i];
            }
        }

        cin >> m;

        while (m--) {
            cin >> comm;

            int f = conv[comm[0]];
            int cnt = conv[comm[1]];
            rotate((FACE)f, cnt);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << arr[cube[U][i][j]];
            }
            cout << '\n';
        }
    }
}