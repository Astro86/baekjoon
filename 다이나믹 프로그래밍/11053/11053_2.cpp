#include <iostream>
#include <vector>
using namespace std;

int n;

int main(void)
{
    cin >> n;

    vector<int> v(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int limit = v[i];
        int maxValue = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] < limit && maxValue < dp[j]) {
                maxValue = dp[j];
            }
        }
        dp[i] = maxValue + 1;
    }

    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << '\n';
    return 0;
}