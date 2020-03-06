#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n, m;

int lower_bound(int target)
{
    int start, mid, end;
    start = 0;
    end = n;

    while (end > start)
    {
        mid = (start + end) / 2;

        if (target <= arr[mid])
            end = mid;
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int upper_bound(int target)
{
    int start, end, mid;
    start = 0;
    end = n;

    while (end > start)
    {
        mid = (start + end) / 2;

        if (target < arr[mid])
            end = mid;
        else
        {
            start = mid + 1;
        }
    }
    return end;
}
int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int target, start_index, end_index = 0;
        scanf("%d", &target);
        start_index = lower_bound(target);
        end_index = upper_bound(target);
        printf("%d ", end_index - start_index);
    }
    return 0;
}