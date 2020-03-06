#include <iostream>
using namespace std;

int a[51][51];
int b[51][51];
int N, M;

void transform(int y, int x)
{
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            if (a[i][j] == 0)
                a[i][j] = 1;
            else {
                a[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &b[i][j]);
        }
    }

    int num = 0;
    if (N >= 3 && M >= 3) {
        for (int i = 0; i <= N - 3; i++) {
            for (int j = 0; j <= M - 3; j++) {
                if (a[i][j] != b[i][j]) {
                    num++;
                    transform(i, j);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << num << '\n';
    return 0;
}