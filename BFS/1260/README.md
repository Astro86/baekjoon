# 백준 1260 - DFS와 BFS

![](1260.jpeg)

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int map[1001][1001];
bool dfs_check[1001];
bool bfs_check[1001];

void dfs(int node) {
    cout << node << ' ';
    dfs_check[node] = true;
    for (int i = 1; i <= N; i++) {
        if (::map[node][i] == 1 && dfs_check[i] == false) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bfs_check[start] = true;

    cout << start << ' ';

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (::map[cnt][i] == 1 && bfs_check[i] == false) {
                bfs_check[i] = true;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        ::map[a][b] = 1;
        ::map[b][a] = 1;
    }

    dfs(V);
    cout << '\n';
    bfs(V);
    cout << '\n';

    return 0;
}
```

## java 코드
```java
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int n, m, v;
    static int map[][];
    static boolean bfs_check[];
    static boolean dfs_check[];

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();

        map = new int[n + 1][n + 1];

        for (int i = 0; i < m; i++) {
            int from, to;
            from = sc.nextInt();
            to = sc.nextInt();

            map[from][to] = 1;
            map[to][from] = 1;
        }
        bfs_check = new boolean[n + 1];
        dfs_check = new boolean[n + 1];

        dfs(v);
        System.out.println();
        bfs(v);

        sc.close();
    }

    static void dfs(int node) {
        System.out.print(Integer.toString(node) + ' ');
        dfs_check[node] = true;

        for (int i = 1; i <= n; i++) {
            if (map[node][i] == 1 && dfs_check[i] == false) {
                dfs(i);
            }
        }
    }

    static void bfs(int start) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(start);
        bfs_check[start] = true;

        System.out.print(Integer.toString(start) + ' ');

        while (!q.isEmpty()) {
            int cnt = q.remove();

            for (int i = 1; i <= n; i++) {
                if (map[cnt][i] == 1 && bfs_check[i] == false) {
                    bfs_check[i] = true;
                    q.offer(i);
                    System.out.print(Integer.toString(i) + ' ');
                }
            }
        }
    }
}
```

## python 코드
```python
def bfs(start):
    queue = [start]
    bfs_check = [start]

    while queue:
        cnt_node = queue.pop(0)

        for next_node in range(len(matrix[cnt_node])):
            if(matrix[cnt_node][next_node] == 1 and next_node not in bfs_check):
                bfs_check.append(next_node)
                queue.append(next_node)

    return bfs_check


def dfs(cnt_node):
    dfs_check.append(cnt_node)

    for next_node in range(len(matrix[cnt_node])):
        if(matrix[cnt_node][next_node] == 1 and next_node not in dfs_check):
            dfs(next_node)


N, M, V = map(int, input().split())
matrix = [[0] * (N+1) for i in range(N+1)]
dfs_check = []

for i in range(M):
    point = list(map(int, input().split()))
    matrix[point[0]][point[1]] = 1
    matrix[point[1]][point[0]] = 1

dfs(V)
print(*dfs_check)
print(*bfs(V))
```