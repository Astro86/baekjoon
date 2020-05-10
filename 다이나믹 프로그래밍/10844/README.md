# 백준 10844 - 쉬운 계단 수

![](10844.jpeg)

## 전체 소스 코드
```cpp
#include <iostream>
using namespace std;

int n;
long long dp[110][10];

int main(void) {
    cin >> n;

    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        dp[i][9] = dp[i - 1][8] % 1000000000;

        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    long long total = 0;

    for (int i = 0; i < 10; i++) {
        total += dp[n][i];
    }

    cout << total % 1000000000 << '\n';
    return 0;
}
```