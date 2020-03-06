#include <iostream>
#include <string>
using namespace std;

string s;
string result = "";

int main(void)
{
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            result += s[i];
        }
    }

    cout << result << '\n';
    return 0;
}