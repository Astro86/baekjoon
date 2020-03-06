#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_RANGE 10000000
int a[MAX_RANGE];

int choosePivot(int low, int high)
{
    return (high + low) / 2;
}

int partition(int low, int high)
{
    int pivotIndex = choosePivot(low, high);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[high]);
    int index = low;

    for (int i = low; i < high; i++)
    {
        if (a[i] < pivotValue)
        {
            swap(a[i], a[index]);
            index++;
        }
    }

    swap(a[index], a[high]);
    return index;
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quicksort(low, pivot - 1);
        quicksort(pivot + 1, high);
    }
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}