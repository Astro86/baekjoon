#include <bits/stdc++.h>
using namespace std;

string word;
vector<string> croatia_word = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
    cin >> word;

    for (int i = 0; i < croatia_word.size(); i++) {
        while (word.find(croatia_word[i]) != string::npos) {
            int start = word.find(croatia_word[i]);
            word.replace(start, croatia_word[i].length(), "*");
        }
    }

    cout << word.length() << '\n';
    return 0;
}