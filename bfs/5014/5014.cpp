#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int check[1000001];

int main(void)
{
    cin >> F >> S >> G >> U >> D;

    queue<pair<int, int>> q;
    q.push({ S, 0 });
    check[S] = true;
    bool isPass = true;
    while (!q.empty()) {
        int cnt = q.front().first;
        int num = q.front().second;
        q.pop();

        if (cnt == G) {
            cout << num << '\n';
            isPass = false;
        }

        int next1 = cnt + U;
        int next2 = cnt - D;

        if (0 <= next1 && next1 <= F) {
            if (check[next1] == false) {
                check[next1] = true;
                q.push({ next1, num + 1 });
            }
        }

        if (0 <= next2 && next2 <= F) {
            if (check[next2] == false) {
                check[next2] = true;
                q.push({ next2, num + 1 });
            }
        }
    }

    if (isPass) {
        cout << "use the stairs" << '\n';
    }
    return 0;
}