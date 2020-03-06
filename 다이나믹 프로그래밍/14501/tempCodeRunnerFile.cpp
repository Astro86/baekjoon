#include <iostream>
using namespace std;

int N;
pair<int, int> consult[20];
int pay[20];

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int time, price;
        cin >> time >> price;

        consult[i] = { time, price };
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << consult[i].first << " " << consult[i].second << endl;
    // }

    for (int i = 1; i <= N; i++) {
        int time = consult[i].first;
        int price = consult[i].second;
        int nextTime = i + time;

        if (nextTime >= N + 1) {
            continue;
        }

        if (pay[nextTime] < pay[i] + price) {
            pay[nextTime] = pay[i] + price;
        }
    }

    // for (int i = 1; i < N + 1; i++) {
    //     cout << pay[i] << " ";
    // }

    int maxValue = 0;
    for (int i = 1; i < N + 1; i++) {
        if (maxValue < pay[i])
            maxValue = pay[i];
    }
    cout << maxValue << endl;
}