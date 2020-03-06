#include <iostream>
using namespace std;

int n, k;
int arr[110];
int dp[10010];
int INF = 1000000000;

int main(void)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= k; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int value = arr[i];

            if (j - value >= 0) {
                dp[j] = min(dp[j], dp[j - value] + 1);
            }
        }
    }

    if (dp[k] != INF)
        cout << dp[k] << '\n';
    else {
        cout << -1 << '\n';
    }
}