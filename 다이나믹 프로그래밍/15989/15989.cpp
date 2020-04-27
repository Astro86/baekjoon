#include <bits/stdc++.h>
using namespace std;

int T;
int dp[10010];

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;

    dp[0] = 1;
    for (int i = 0; i <= 10000; i++) {
        dp[i + 1] += dp[i];
    }
    for (int i = 0; i <= 10000; i++) {
        dp[i + 2] += dp[i];
    }
    for (int i = 0; i <= 10000; i++) {
        dp[i + 3] += dp[i];
    }

    while (T--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
    return 0;
}