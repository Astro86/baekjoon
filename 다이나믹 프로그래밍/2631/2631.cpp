#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(void) {
    int n;
    cin >> n;
    v = vector<int>(n + 1);
    vector<int> dp(n + 1);

    v[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i <= n; i++) {
        int cntValue = v[i];

        for (int j = i + 1; j <= n; j++) {
            if (v[j] >= cntValue) {
                if (dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }

    int maxValue = *max_element(dp.begin() + 1, dp.end() + 1);
    cout << n - maxValue << '\n';
    return 0;
}