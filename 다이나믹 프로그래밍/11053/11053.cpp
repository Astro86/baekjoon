#include <algorithm>
#include <iostream>
using namespace std;

int N;
int arr[1001];
int dp[1001];

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int limit = arr[i];

        int maxlength = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < limit) {
                if (maxlength < dp[j]) {
                    maxlength = dp[j];
                }
            }
        }
        dp[i] = maxlength + 1;
    }

    int maxValue = 0;
    for (int i = 1; i <= N; i++) {
        maxValue = max(maxValue, dp[i]);
    }

    cout << maxValue << '\n';

    return 0;
}