#include <iostream>
using namespace std;

#define MAX_VALUE 1000001
int n, m;
int parent[MAX_VALUE];

int find(int a)
{
    if (parent[a] == a)
        return a;
    else
    {
        return parent[a] = find(parent[a]);
    }
}

void merge(int a, int b)
{
    int set_a = find(a);
    int set_b = find(b);

    if (set_a == set_b)
        return;

    parent[set_b] = set_a;
}

int main(void)
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n + 1; i++)
        parent[i] = i;

    while (m--)
    {
        int o, a, b;
        scanf("%d %d %d", &o, &a, &b);

        if (o == 0)
            merge(a, b);
        else if (o == 1)
        {
            int set_a = find(a);
            int set_b = find(b);

            if (set_a == set_b)
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}