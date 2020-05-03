#include <bits/stdc++.h>
using namespace std;

string name;
int ohminsick[26];
pair<int, string> arr[55];
int n;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(void) {
    cin >> name >> n;

    for (int i = 0; i < name.size(); i++) {
        ohminsick[name[i] - 'A']++;
    }

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        int spelling[26];
        memset(spelling, 0, sizeof(spelling));
        for (int j = 0; j < temp.size(); j++) {
            spelling[temp[j] - 'A']++;
        }

        int L = spelling['L' - 'A'] + ohminsick['L' - 'A'];
        int O = spelling['O' - 'A'] + ohminsick['O' - 'A'];
        int V = spelling['V' - 'A'] + ohminsick['V' - 'A'];
        int E = spelling['E' - 'A'] + ohminsick['E' - 'A'];

        int total = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        arr[i] = {total, temp};
    }

    sort(arr, arr + n, cmp);

    cout << arr[0].second << '\n';
}