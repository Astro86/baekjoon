#include <iostream>
#include <algorithm>
using namespace std;

int v, e, a, b, c, i, cnt, sum;
struct edge
{
    int weight, from, to;
};

bool operator<(const edge &e1, const edge &e2)
{
    return e1.weight < e2.weight;
}

edge E[100001];
int parent[100001];
int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    x = parent[x];
    y = parent[y];
    parent[x] = y;
}

int main(void)
{
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        E[i] = {c, a, b};
    }

    for (int i = 1; i <= v; i++)
        parent[i] = i;
    sort(E, E + e);

    i = 0;
    while (cnt != v - 1)
    {
        a = E[i].from;
        b = E[i].to;
        if (find(a) != find(b))
        {
            merge(a, b);
            cnt++;
            sum += E[i].weight;
        }
        i++;
    }
    printf("%d", sum);
    return 0;
}