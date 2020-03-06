#include <iostream>
using namespace std;

int x, y;
int arr[303][303];
int load[303][303];

int main(void)
{
    cin >> x >> y;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> arr[i][j];

            load[i][j] = load[i][j - 1] + load[i - 1][j] - load[i - 1][j - 1] + arr[i][j];
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        int sum;
        sum = load[endX][endY] - load[startX - 1][endY] - load[endX][startY - 1] + load[startX - 1][startY - 1];

        cout << sum << '\n';
    }

    return 0;
}