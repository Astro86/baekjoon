# 백준 2798 - 블랙잭

[2798 - 블랙잭](https://www.acmicpc.net/problem/2798)

![](2798.jpeg)

## 2798

```cpp
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

    // 현재 카드를 선택 한 경우
    find_max(count + 1, index + 1, sum + v[index]);
    // 현재 카드를 선택 하지 않은 경우
    find_max(count, index + 1, sum);
}
```

`DFS`를 이용하여 문제를 해결하였다.  
카드는 2개의 상태를 가질 수 있다. `카드를 선택한 경우`와 `카드를 선택하지 않은 경우`  
현재 카드를 선택한 경우와 현재 카드를 선택하지 않은 경우 두가지 경우로 나누어서 재귀 함수를 호출 하였다. 경우의 수를 다 따져가며 완전탐색을 하게 된다.

## 전체 소스 코드
```cpp
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
```

## 전체 소스 코드 2

```cpp
void blackJack(int start_index, int sum, int depth)
{
    if (sum > sum_limit)
        return;

    if (depth == 3)
    {
        if (max_sum < sum)
        {
            max_sum = sum;
            return;
        }
        return;
    }

    for (int i = start_index; i < n; i++)
    {
        blackJack(i + 1, sum + card[i], depth + 1);
    }
}
```

`DFS`를 이용하여 문제를 해결한 두번째 방법
가지고 있는 카드를 한번에 고려하는 상황으로 알고리즘을 짯다.


```cpp
#include <iostream>
#include <vector>
using namespace std;

int n;
int sum_limit;
int max_sum;
vector<int> card;

void blackJack(int start_index, int sum, int depth)
{
    if (sum > sum_limit)
        return;

    if (depth == 3)
    {
        if (max_sum < sum)
        {
            max_sum = sum;
            return;
        }
        return;
    }

    for (int i = start_index; i < n; i++)
    {
        blackJack(i + 1, sum + card[i], depth + 1);
    }
}

int main(void)
{
    scanf("%d %d", &n, &sum_limit);
    card = vector<int>(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    blackJack(0, 0, 0);

    printf("%d\n", max_sum);
    return 0;
}
```

## 전체 소스 코드 3

```cpp
void blackJack()
{
    while (!q.empty())
    {
        int start_index = q.front().start_index;
        int sum = q.front().sum;
        int level = q.front().level;
        q.pop();

        if (start_index > n || sum > sum_limit)
            continue;

        if (level == 3)
        {
            if (max_sum < sum)
            {
                max_sum = sum;
                continue;
            }
            continue;
        }
        else if (level > 3)
            break;

        for (int i = start_index; i < n; i++)
        {
            card_sum temp(i + 1, sum + card[i], level + 1);
            q.push(temp);
        }
    }
}
```

`BFS`를 이용하여 문제를 해결


```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int sum_limit;
int max_sum;
vector<int> card;
struct card_sum
{
    int start_index;
    int sum;
    int level;
    card_sum(int i, int j, int k) : start_index(i), sum(j), level(k) {}
};
queue<card_sum> q;

void blackJack()
{
    while (!q.empty())
    {
        int start_index = q.front().start_index;
        int sum = q.front().sum;
        int level = q.front().level;
        q.pop();

        if (start_index > n || sum > sum_limit)
            continue;

        if (level == 3)
        {
            if (max_sum < sum)
            {
                max_sum = sum;
                continue;
            }
            continue;
        }
        else if (level > 3)
            break;

        for (int i = start_index; i < n; i++)
        {
            card_sum temp(i + 1, sum + card[i], level + 1);
            q.push(temp);
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &sum_limit);
    card = vector<int>(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    card_sum temp(0, 0, 0);
    q.push(temp);
    blackJack();

    printf("%d\n", max_sum);
    return 0;
}
```
