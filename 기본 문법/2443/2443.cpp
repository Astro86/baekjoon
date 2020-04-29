#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << '*';
        }
        cout << endl;
    }
}