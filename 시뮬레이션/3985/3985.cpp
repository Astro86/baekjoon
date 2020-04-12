#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int L, N;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main(void) {
    cin >> L >> N;
    vector<pair<int, int>> audience(N + 1);
    vector<int> cake(L + 1, 0);
    vector<pair<int, int>> v(N + 1);

    for (int i = 1; i <= N; i++) {
        audience[i].first = 0;
        audience[i].second = i;
    }

    int maxDist = 0;
    int minIndex = 0;
    for (int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;

        if (maxDist < abs(v[i].first - v[i].second)) {
            maxDist = abs(v[i].first - v[i].second);
            minIndex = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        int from, to;
        from = v[i].first;
        to = v[i].second;

        for (int j = from; j <= to; j++) {
            if (cake[j] == 0) {
                cake[j] = i;
            }
        }
    }

    for (int i = 1; i <= L; i++) {
        audience[cake[i]].first++;
    }
    sort(audience.begin() + 1, audience.end(), cmp);

    cout << minIndex << '\n';
    cout << audience[1].second << '\n';
    return 0;
}