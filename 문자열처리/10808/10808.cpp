#include <iostream>
#include <string>
using namespace std;

string s;
int alphabet[26];

int main(void)
{
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }

    return 0;
}