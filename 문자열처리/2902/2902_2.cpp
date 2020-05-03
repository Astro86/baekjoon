#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
    cin >> s;
    stringstream ss;
    ss.str(s);

    string temp;
    while (getline(ss, temp, '-')) {
        cout << temp[0];
    }
    return 0;
}