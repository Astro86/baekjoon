#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - n] << '\n';
    return 0;
}