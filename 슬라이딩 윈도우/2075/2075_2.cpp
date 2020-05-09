#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    int value;
    for (int i = 0; i < n * n; i++) {
        cin >> value;

        if (pq.size() < n) {
            pq.push(value);
        } else {
            if (pq.top() < value) {
                pq.pop();
                pq.push(value);
            }
        }
    }
    cout << pq.top() << '\n';
    return 0;
}