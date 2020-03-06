#include <iostream>
#include <vector>
using namespace std;

int n, m, s, e;
int arr[1001][1001];
int dis[1001];
int initial_value = 100000000;
bool check[1001];

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        dis[i] = initial_value;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = initial_value;

    for (int i = 1; i <= m; i++)
    {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        if (arr[v1][v2] > weight)
            arr[v1][v2] = weight;
    }

    scanf("%d %d", &s, &e);
    dis[s] = 0;
    int num = n;

    while (num--)
    {
        int cnt;
        int min = initial_value;
        for (int i = 1; i <= n; i++)
        {
            if (min > dis[i] && check[i] == false)
            {
                min = dis[i];
                cnt = i;
            }
        }
        check[cnt] = true;

        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > dis[cnt] + arr[cnt][i])
                dis[i] = dis[cnt] + arr[cnt][i];
        }
    }

    printf("%d\n", dis[e]);
    return 0;
}