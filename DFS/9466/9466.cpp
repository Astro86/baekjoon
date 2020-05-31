#include <iostream>
using namespace std;

int testCase, n;
int student[100010];
bool check[1000010];
bool team[1000010];
int teams = 0;

void dfs(int cnt)
{
    check[cnt] = true;
    int next = student[cnt];

    if (check[next] == true) {
        if (team[next] == false) {
            for (int x = next; x != cnt; x = student[x])
                teams++;
            teams++;
        }
    } else {
        dfs(next);
    }
    team[cnt] = true;
}

int main(void)
{
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for (int i = 1; i <= n; i++) {
            if (check[i] == false) {
                dfs(i);
            }
        }

        int result = n - teams;
        cout << result << '\n';

        for (int i = 1; i <= n; i++) {
            student[i] = 0;
            check[i] = false;
            team[i] = 0;
            teams = 0;
        }
    }

    return 0;
}