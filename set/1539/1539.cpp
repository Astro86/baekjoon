#include <bits/stdc++.h>
using namespace std;

set<int> s;
int heights[250002];
long long sum = 0;

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        int value;
        cin >> value;

        auto iter = s.lower_bound(value);

        long long left, right;
        if (iter != s.begin()) {
            auto left_iter = iter;
            left = heights[*(--left_iter)];
        } else {
            left = 0;
        }

        if (iter != s.end()) {
            right = heights[*iter];
        } else {
            right = 0;
        }

        heights[value] = max(left, right) + 1;
        s.insert(value);

        sum += heights[value];
    }

    cout << sum << endl;
}