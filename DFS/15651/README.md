# 백준 15651 - N과 M(3)

[15651 - N과 M(3)](https://www.acmicpc.net/problem/15651)

![](15651m.png)

```cpp
#include <iostream>
using namespace std;

const int MAX = 8 + 1;
int N, M;
int arr[MAX];

void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        arr[depth] = i;
        dfs(depth + 1);
    }
}

int main(void)
{
    cin >> N >> M;
    dfs(0);
    return 0;
}
```
