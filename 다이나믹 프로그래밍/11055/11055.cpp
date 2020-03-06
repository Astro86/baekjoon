#include <iostream>
using namespace std;

int n;
int arr[1010];
int dp[1010];

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int maxValue = 0;
    for (int i = 1; i <= n; i++) {
        int limit = arr[i];

        for (int j = 0; j < i; j++) {
            if (arr[j] < limit) {
                if (maxValue < dp[j]) {
                    maxValue = dp[j];
                }
            }
        }
        dp[i] = maxValue + arr[i];
    }

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << endl;

    return 0;
}