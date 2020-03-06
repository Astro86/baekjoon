#include <iostream>
#include <string>
using namespace std;

int T;
int num;

int main(void)
{
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool check[26];
        for (int i = 0; i < 26; i++) {
            check[i] = false;
        }

        int stringSize = s.size();
        bool isContinue = true;
        for (int i = 0; i < stringSize; i++) {
            char cntChar = s[i];
            int cntIndex = cntChar - 'a';

            if (check[cntIndex] == false) {
                check[cntIndex] = true;
                for (char c = cntChar; c == s[i]; s[i++]) {
                }
                i--;

            } else {
                isContinue = false;
            }
        }

        if (isContinue == true) {
            num++;
        }
    }

    cout << num << '\n';
    return 0;
}