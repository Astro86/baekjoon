#include <iostream>
using namespace std;

const int MAX = 8 + 1;
int N, M;
int arr[MAX];
int visited[MAX];

void dfs(int cnt, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = cnt; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[depth] = i;
            dfs(i, depth + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M;
    dfs(1, 0);
    return 0;
}