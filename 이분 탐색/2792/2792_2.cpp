#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> jewelry;
int answer = INT_MAX;

bool inN(int value) {
    int maxValue = 0;
    int num = 0;
    for (int i = 0; i < M; i++) {
        num += (jewelry[i] / value);
        maxValue = max(maxValue, value + (jewelry[i] % value));
    }

    if (num <= N) {
        answer = min(answer, maxValue);
        return true;
    } else {
        return false;
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    jewelry = vector<int>(M);

    int length = 0;
    for (int i = 0; i < M; i++) {
        cin >> jewelry[i];

        if (jewelry[i] > length) {
            length = jewelry[i];
        }
    }

    int start = 1;
    int finish = length;
    while (start <= finish) {
        int mid = (start + finish) / 2;

        if (inN(mid)) {
            finish = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}