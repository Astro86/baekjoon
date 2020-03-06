#include <iostream>
#include <algorithm>
using namespace std;

// 입력
// 첫째 줄에는 숫자 카드의 개수 N
// 둘째 줄에는 숫자가드에 적혀있는 정수가 주어진다.
// 셋째 줄에는 M이 주어진다.
// 넷째 줄에는 상근이가 몇개 가지고 있는 숫자 카드인지 구해야할 M개의 정수가 주어진다.
int N, M;
int arr[500001];

int lower_bound(int value)
{
    int start = 0;
    int end = N;
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (value <= arr[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return end;
}

int upper_bound(int value)
{
    int start = 0;
    int end = N;
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (value < arr[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int temp, lowerIndex, upperIndex;
        scanf("%d", &temp);
        lowerIndex = lower_bound(temp);
        upperIndex = upper_bound(temp);

        printf("%d ", upperIndex - lowerIndex);
    }
    return 0;
}
