#include <iostream>
using namespace std;

int N;
int T[22];
int P[22];
int money[22];

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        int n = T[i];
        int nTime = i + n + -1;
        int nMoney = money[i - 1] + P[i];

        money[nTime] = max(money[nTime], nMoney);

        money[i] = max(money[i], money[i - 1]);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << money[i] << " ";
    // }
    // cout << endl;

    cout << money[N] << '\n';

    return 0;
}