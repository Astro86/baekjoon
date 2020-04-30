#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string command;

int main(void) {
    cin >> n;

    vector<string> files(n);

    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    command = files[0];
    for (int i = 1; i < files.size(); i++) {
        for (int j = 0; j < command.size(); j++) {
            if (command[j] != files[i][j]) {
                if (command[j] == '?') {
                    continue;
                }
                command[j] = '?';
            }
        }
    }

    cout << command << '\n';
    return 0;
}