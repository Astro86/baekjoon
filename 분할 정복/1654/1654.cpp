#include <iostream>
#include <vector>
using namespace std;

int k, n;
long long n_length;
long long max_length;

int main(void)
{
    scanf("%d %d", &k, &n);
    vector<long long> k_length(k);

    for (int i = 0; i < k; i++)
    {
        long long temp;
        scanf("%lld", &temp);
        k_length[i] = temp;
        if (temp > max_length)
            max_length = temp;
    }

    long long start = 1;
    long long end = max_length;

    while (start <= end)
    {
        int num = 0;
        long long mid = (start + end) / 2;

        for (int i = 0; i < k; i++)
        {
            num += (k_length[i] / mid);
        }

        // n보다 개수가 많은경우
        if (num >= n)
        {
            if (n_length < mid)
                n_length = mid;
            start = mid + 1;
        }
        // n보다 개수가 모자른 경우
        else if (num < n)
        {
            end = mid - 1;
        }
    }

    printf("%lld", n_length);

    return 0;
}