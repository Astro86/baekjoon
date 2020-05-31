#include <iostream>
using namespace std;

int testCase, n;
int student[100001];
bool check[100001];
int team[100001];

void dfs(int cnt)
{
    check[cnt] = true;
    int next = student[cnt];

    if (check[next] == true) {
        if (team[next] == 0) {
            team[next] = 1;
            dfs(next);
        }
    } else
        dfs(next);
    if (team[cnt] != 1) {
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
                check[i] = true;
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