#include <iostream>
using namespace std;

int testCase, n;
int student[100010];
bool check[1000010];
int team[1000010];

void dfs(int cnt)
{
    check[cnt] = true;
    int next = student[cnt];

    if (check[next] == true) {
        if (team[next] == 0) {
            team[next] = 1;
            dfs(next);
        }
        return;
    }

    dfs(next);
    if (team[cnt] == 0) {
        team[cnt] = 2;
    }
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

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (team[i] != 1)
                result++;
        }

        cout << result << '\n';

        for (int i = 1; i <= n; i++) {
            student[i] = 0;
            check[i] = false;
            team[i] = 0;
        }
    }

    return 0;
}