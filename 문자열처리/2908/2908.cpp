#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string num1, num2;
    cin >> num1 >> num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    if (num1 > num2) {
        cout << num1 << '\n';
    } else {
        cout << num2 << '\n';
    }

    return 0;
}