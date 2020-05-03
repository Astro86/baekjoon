#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int num = 0;
    string code_name;

    for (int i = 0; i < 5; i++) {
        getline(cin, code_name, '\n');

        if (code_name.find("FBI") != string::npos) {
            cout << i + 1 << ' ';
            num++;
        }
    }

    if (num == 0)
        cout << "HE GOT AWAY!" << '\n';

    return 0;
}