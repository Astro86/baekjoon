#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;

int main(void)
{
    scanf("%d %d", &n, &c);
    vector<long long> house_locate(n);

    for (int i = 0; i < n; i++)
    {
        long long temp;
        scanf("%lld", &temp);
        house_locate[i] = temp;
    }

    sort(house_locate.begin(), house_locate.end());

    long long start = 1;
    long long end = house_locate[n - 1] - house_locate[0];

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long num = 1;

        long long pre = house_locate[0];
        for (int i = 0; i < n; i++)
        {
            long long distance = house_locate[i] - pre;
            if (distance >= mid)
            {
                pre = house_locate[i];
                num++;
            }
        }

        if (num < c)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    printf("%lld", end);
}