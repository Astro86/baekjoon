#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int G;
    int num = 0;
    vector<int> v;
    cin >> G;

    for (long long i = sqrt(G); i <= 50000; i++) {
        for (long long j = 1; j < i; j++) {
            long long cnt_value = i * i - j * j;

            if (cnt_value < G) {
                break;
            }

            if (cnt_value == G) {
                v.push_back(i);
            }
        }
    }
    if (v.size() == 0) {
        cout << -1 << '\n';
    } else {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << '\n';
        }
    }

    return 0;
}