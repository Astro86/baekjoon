#include <iostream>
using namespace std;

int N, M;
int arr[55][55];
int maxValue = 1;

void findSquare(int y, int x)
{
    for (int i = x + 1; i < M; i++) {
        if (arr[y][i] == arr[y][x]) {
            bool isSqure = true;
            int dis = i - x;

            if (y + dis >= N || x + dis >= M) {
                continue;
            }

            if (arr[y + dis][x] != arr[y][x]) {
                isSqure = false;
            }
            if (arr[y + dis][x + dis] != arr[y][x]) {
                isSqure = false;
            }

            if (isSqure == true) {
                if (maxValue < (dis + 1) * (dis + 1)) {
                    // cout << y << " " << x << " " << dis << endl;
                    maxValue = (dis + 1) * (dis + 1);
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            findSquare(i, j);
        }
    }

    cout << maxValue << '\n';
    return 0;
}