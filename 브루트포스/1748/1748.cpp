#include <iostream>
#include <string>
using namespace std;

int num;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 100000000) {
            num += 9;
        } else if (i >= 10000000) {
            num += 8;
        } else if (i >= 1000000) {
            num += 7;
        } else if (i >= 100000) {
            num += 6;
        } else if (i >= 10000) {
            num += 5;
        } else if (i >= 1000) {
            num += 4;
        } else if (i >= 100) {
            num += 3;
        } else if (i >= 10) {
            num += 2;
        } else {
            num += 1;
        }
    }

    cout << num << '\n';
    return 0;
}