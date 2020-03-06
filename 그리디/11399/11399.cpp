#include <algorithm>
#include <iostream>
using namespace std;

int Time[1010];
int timeStack[1010];

int totalTime;
int n;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> Time[i];
    }

    sort(Time, Time + n);
    timeStack[0] = Time[0];

    for (int i = 1; i < n; i++) {
        timeStack[i] = Time[i] + timeStack[i - 1];
    }

    for (int i = 0; i < n; i++) {
        totalTime += timeStack[i];
    }

    cout << totalTime << '\n';
    return 0;
}