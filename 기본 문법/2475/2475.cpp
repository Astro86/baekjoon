#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        int value;
        cin >> value;
        total += pow(value, 2);
    }
    cout << total % 10 << '\n';
    return 0;
}