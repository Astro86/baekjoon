#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> arr;
bool check[10001];
int hackArr[10001];
int hackNum = 0;

vector<int> v;

int maxHackNum;

void dfs(int cnt)
{

    if (maxHackNum < hackNum)
        maxHackNum = hackNum;

    for (int i = 0; i < arr[cnt].size(); i++) {
        int next = arr[cnt][i];
        if (check[next] == false) {
            check[next] = true;
            hackNum++;
            dfs(next);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        arr[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        hackNum++;
        check[i] = true;
        dfs(i);
        hackArr[i] = hackNum;

        for (int j = 1; j <= N; j++) {
            check[j] = false;
        }
        hackNum = 0;
    }

    for (int i = 1; i <= N; i++) {
    }

    for (int i = 1; i <= N; i++) {
        if (hackArr[i] == maxHackNum)
            cout << i << " ";
    }
    cout << '\n';

    return 0;
}