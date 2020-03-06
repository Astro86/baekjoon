# 백준 2193 - 이천수

```cpp
#include <iostream>
using namespace std;

long long dp[99][2];
int n;

long long solution(int n, int m)
{
    if (n == 0 || dp[n][m] != 0)
    {
        return dp[n][m];
    }
    dp[n][0] = solution(n - 1, 0) + solution(n - 1, 1);
    dp[n][1] = solution(n - 1, 0);

    return dp[n][m];
}

int main(void)
{
    scanf("%d", &n);
    dp[0][0] = 0;
    dp[0][1] = 1;

    long long num0 = solution(n, 0);

    printf("%lld\n", num0);

    return 0;
}
```
