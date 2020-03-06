#include <iostream>
using namespace std;

int n;
int arr[1010];
int dp[1010];

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int limit = arr[i];
        dp[i] = arr[i];

        for (int j = 0; j < i; j++) {
            if (arr[j] < limit && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << endl;

    return 0;
}