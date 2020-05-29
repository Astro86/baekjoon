#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int G;
    int num = 0;
    vector<int> v;
    cin >> G;

    long long e = 1;
    long long s = 1;
    bool existed = false;

    while (true) {
        if (e * e - s * s == G) {
            existed = true;
            cout << e << '\n';
        }
        if (e - s == 1 && e * e - s * s > G)
            break;
        if (e * e - s * s > G)
            s++;
        else
            e++;
    }

    if (!existed)
        cout << -1;

    return 0;
}