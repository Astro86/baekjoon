#include <iostream>
#include <string>
using namespace std;

string s;

int main(void) {
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        int cntChar = s[i];
        num++;

        if (cntChar == 'c') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == '=') {
                    i++;
                }

                if (nextChar == '-') {
                    i++;
                }
            }
        }

        if (cntChar == 'd') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == 'z') {
                    if (i + 2 < s.size()) {
                        int next_nextChar = s[i + 2];

                        if (next_nextChar == '=') {
                            i += 2;
                        }
                    }
                }

                if (nextChar == '-') {
                    i++;
                }
            }
        }

        if (cntChar == 'l') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == 'j') {
                    i++;
                }
            }
        }

        if (cntChar == 'n') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == 'j') {
                    i++;
                }
            }
        }

        if (cntChar == 's') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == '=') {
                    i++;
                }
            }
        }

        if (cntChar == 'z') {
            if (i + 1 < s.size()) {
                int nextChar = s[i + 1];

                if (nextChar == '=') {
                    i++;
                }
            }
        }
    }

    cout << num << '\n';
    return 0;
}