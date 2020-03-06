#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

bool order(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first ? true : false;
}

int main(void)
{
    cin >> T;

    while (T--) {
        cin >> N;
        vector<pair<int, int>> v;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({ a, b });
        }

        sort(v.begin(), v.end(), order);

        int num = 1;
        int pivot = v[0].second;
        for (int i = 1; i < N; i++) {
            if (pivot > v[i].second) {
                pivot = v[i].second;
                num++;
            }
        }

        cout << num << '\n';
    }
    return 0;
}