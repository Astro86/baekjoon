#include <iostream>
using namespace std;

int stair[301];
int stair_sum[301][3];
int n;

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &stair[i]);
    }

    stair_sum[1][1] = stair[1];

    for (int i = 2; i <= n; i++)
    {
        stair_sum[i][2] = stair_sum[i - 1][1] + stair[i];
        stair_sum[i][1] = max(stair_sum[i - 2][1], stair_sum[i - 2][2]) + stair[i];
    }

    printf("%d\n", max(stair_sum[n][1], stair_sum[n][2]));
    return 0;
}