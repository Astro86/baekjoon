#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<pair<string, int>> names;
vector<string> copy_names;

void searchName(string& name) {
    int start, end, mid;
    start = 0;
    end = N;

    while (start <= end) {
        mid = (start + end) / 2;

        if (names[mid].first == name) {
            cout << names[mid].second << '\n';
            break;
        } else if (names[mid].first < name) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    names = vector<pair<string, int>>(N + 1);
    copy_names = vector<string>(N + 1);

    for (int i = 0; i < N; i++) {
        string stemp;
        cin >> stemp;
        names[i] = {stemp, i + 1};
        copy_names[i] = stemp;
    }

    sort(names.begin(), names.end());

    while (M--) {
        string s;
        cin >> s;

        if (isdigit(s[0])) {
            int number = stoi(s);
            cout << copy_names[number - 1] << '\n';
        } else {
            searchName(s);
        }
    }
    return 0;
}
