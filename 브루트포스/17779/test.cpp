#include <iostream>
using namespace std;

int N;
int map[22][22];
int color[22][22];
int MinDist = 987654321;

int main(void) {
    int N = 7;
    // cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            color[i][j] = 0;
        }
    }

    int x = 2, y = 5, d1 = 3, d2 = 2;

    // 5에 대한 색칠을 칠해준다.
    for (int i = 0; i <= d1; i++) {
        for (int j = i; j <= d1; j++) {
            color[y - i][x + j] = 5;
        }
    }

    for (int i = 0; i <= d2; i++) {
        for (int j = i; j <= d2; j++) {
            color[y + i][x + j] = 5;
        }
    }

    for (int i = 0; i < d2; i++) {
        for (int j = i; j <= d2; j++) {
            color[y - d1 + d2 - i][x + d1 + d2 - j] = 5;
        }
    }

    for (int i = 0; i < d1; i++) {
        for (int j = i; j <= d1; j++) {
            color[y - d1 + d2 + i][x + d1 + d2 - j] = 5;
        }
    }

    // 1에 대해 색칠해주기
    for (int i = 1; i < y; i++) {
        for (int j = 1; j <= x + d1; j++) {
            if (color[i][j] == 0) {
                color[i][j] = 1;
            }
        }
    }

    // 2에 대해 색칠해주기
    for (int i = 1; i <= y - d1 + d2; i++) {
        for (int j = x + d1 + 1; j <= N; j++) {
            if (color[i][j] == 0) {
                color[i][j] = 2;
            }
        }
    }

    // 3에 대해 색칠해주기
    for (int i = y; i <= N; i++) {
        for (int j = 1; j < x + d2; j++) {
            if (color[i][j] == 0) {
                color[i][j] = 3;
            }
        }
    }

    // 4에 대해 색칠해주기
    for (int i = y - d1 + d2 + 1; i <= N; i++) {
        for (int j = x + d2; j <= N; j++) {
            if (color[i][j] == 0) {
                color[i][j] = 4;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << color[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// int main(void) {
//     int N = 7;
//     // cin >> N;

//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cin >> map[i][j];
//         }
//     }

//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             color[i][j] = 0;
//         }
//     }

//     int x = 2, y = 5, d1 = 3, d2 = 2;

//     for (int i = 0; i <= d1; i++) {
//         for (int j = 0; j <= i; j++) {
//             color[x + i][y - j] = 5;
//         }
//     }

//     for (int i = 0; i <= d2; i++) {
//         for (int j = 0; j <= i; j++) {
//             color[x + i][y + j] = 5;
//         }
//     }

//     for (int i = 0; i < d1; i++) {
//         for (int j = 0; j <= i; j++) {
//             color[x + d1 + d2 - i][y - d1 + d2 + j] = 5;
//         }
//     }

//     for (int i = 0; i < d2; i++) {
//         for (int j = 0; j <= i; j++) {
//             color[x + d1 + d2 - i][y - d1 + d2 - j] = 5;
//         }
//     }

//     for (int i = 1; i < x + d1; i++) {
//         for (int j = 1; j <= y; j++) {
//             if (color[i][j] == 0) {
//                 color[i][j] = 1;
//             }
//         }
//     }

//     for (int i = 1; i <= x + d2; i++) {
//         for (int j = y + 1; j <= N; j++) {
//             if (color[i][j] == 0) {
//                 color[i][j] = 2;
//             }
//         }
//     }

//     for (int i = x + d1; i <= N; i++) {
//         for (int j = 0; j < y - d1 + d2; j++) {
//             if (color[i][j] == 0) {
//                 color[i][j] = 3;
//             }
//         }
//     }

//     for (int i = x + d2 + 1; i <= N; i++) {
//         for (int j = y - d1 + d2; j <= N; j++) {
//             if (color[i][j] == 0) {
//                 color[i][j] = 4;
//             }
//         }
//     }

//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             cout << color[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }