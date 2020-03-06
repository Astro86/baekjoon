#include <iostream>
using namespace std;

int N, K;
int dp[1010][1010];

int main(void)
{
    cin >> N >> K;

    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;

        for (int j = 0; j < i; j++) {
            dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1]) % 10007;
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}