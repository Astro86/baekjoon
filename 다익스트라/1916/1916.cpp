#include <iostream>
using namespace std;

int n;
int m;
int s;
int e;
int city[1001][1001];
int Distance[1001];
bool check[1001];

int main(void)
{
    cin>>n;
    cin>>m;

    //처음 초기 값으로는 무한대 값에 가까운 값을 배열에 넣어주어야 한다.
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            city[i][j] = 1000000000;
    }
    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        //점 a에서 점 b까지 가는 방법(간선이) 여러개 일 수 있다.
        if(city[a][b]>w)
            city[a][b] = w;
    }

    cin>>s>>e;


    for(int i=1; i<=n; i++)
    {
        Distance[i] = 1000000000;
    }

    int cnt = s;
    Distance[s] = 0;
    check[s] = true;


    while(cnt != e)
    {
        //printf("cnt : %d\n", cnt);
        for(int i=1; i<=n; i++)
        {
            if(Distance[i] > Distance[cnt]+city[cnt][i])
            {
                Distance[i] = Distance[cnt] + city[cnt][i];
                //printf("%d : %d\n", i, Distance[i]);
            }
        }

        int min = 1000000000;
        for(int i=1; i<=n; i++)
        {
            if(min>Distance[i] && check[i] == false)
            {
                min = Distance[i];
                cnt = i;
            }
        }
        check[cnt] = true;
    }

    printf("%d", Distance[e]);

    return 0;
}           