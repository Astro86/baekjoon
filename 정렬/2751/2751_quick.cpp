#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_RANGE 10000000
int n;
int a[MAX_RANGE];

int choosePivot(int low, int high)
{
    return (low + high) / 2;
}

int partition(int low, int high)
{
    int pivot = choosePivot(low, high);
    int pivotValue = a[pivot];
    swap(a[pivot], a[high]);
    int point = low;

    for (int i = low; i < high; i++)
    {
        if (a[i] < pivotValue)
        {
            swap(a[i], a[point]);
            point++;
        }
    }
    swap(a[point], a[high]);
    return point;
}

void quicksort(int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = partition(low, high);
    quicksort(low, pivot - 1);
    quicksort(pivot + 1, high);
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 정렬을 실시한다.
    quicksort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}