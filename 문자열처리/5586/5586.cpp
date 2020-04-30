#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    cin >> s;

    int JOI_num = 0;
    int IOI_num = 0;

    for (int i = 0; i < s.size() - 2; i++) {
        string temp = s.substr(i, 3);
        if (temp == "JOI") {
            JOI_num++;
        }

        if (temp == "IOI") {
            IOI_num++;
        }
    }

    cout << JOI_num << '\n';
    cout << IOI_num << '\n';
    return 0;
}