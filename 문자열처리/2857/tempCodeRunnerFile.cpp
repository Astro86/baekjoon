#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n = 5;
    vector<int> fbis;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j + 2 <= v[i].size() && v[i][j] == 'F' && v[i][j + 1] == 'B' && v[i][j + 2] == 'I') {
                fbis.push_back(i + 1);
                break;
            }
        }
    }

    if (fbis.size() == 0) {
        cout << "HE GOT AWAY!" << '\n';
    } else {
        for (int i = 0; i < fbis.size(); i++) {
            cout << fbis[i] << ' ';
        }
    }

    return 0;
}