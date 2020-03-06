#include <iostream>
using namespace std;

int T;

int main(void)
{
    cin >> T;

    while (T--) {
        int n;
        int arr[2][100010];
        int score[2][100010];

        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                score[i][j] = 0;
            }
        }

        score[0][0] = arr[0][0];
        score[1][0] = arr[1][0];

        for (int i = 0; i < n; i++) {
            score[1][i + 1] = max(score[0][i] + arr[1][i + 1], score[1][i + 1]);
            score[1][i + 2] = max(score[0][i] + arr[1][i + 2], score[1][i + 2]);
            score[0][i + 1] = max(score[1][i] + arr[0][i + 1], score[0][i + 1]);
            score[0][i + 2] = max(score[1][i] + arr[0][i + 2], score[0][i + 2]);
        }

        cout << max(score[0][n - 1], score[1][n - 1]) << endl;
    }
}