#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int max_sum;

void find_max(int count, int index, int sum)
{
    if (sum > m)
        return;

    if (count == 3)
    {
        if (max_sum < sum)
            max_sum = sum;
        return;
    }

    if (index >= n)
        return;

    find_max(count + 1, index + 1, sum + v[index]);
    find_max(count, index + 1, sum);
}

int main(void)
{
    scanf("%d %d", &n, &m);
    v = vector<int>(n, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    find_max(0, 0, 0);
    printf("%d\n", max_sum);

    return 0;
}