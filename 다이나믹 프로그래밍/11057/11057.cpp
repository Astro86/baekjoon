#include <iostream>
using namespace std;

int N;
int arr[1100];
int dp[1100][10];

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> N;
    }

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[N][i];
    }

    cout << sum % 10007 << '\n';

    return 0;
}