#include <iostream>
using namespace std;

int n;
int total;

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int cntNum = i;
        int num = 0;

        while (cntNum) {
            cntNum /= 10;
            num++;
        }
        total += num;
    }

    cout << total << '\n';
    return 0;
}