#include <iostream>
#include <string>
using namespace std;

string s;

int main(void) {
    cin >> s;

    int length = s.length();
    for (int i = 0; i < length; i += 10) {
        for (int j = i; j < i + 10 && j < length; j++) {
            cout << s[j];
        }
        cout << '\n';
    }

    return 0;
}