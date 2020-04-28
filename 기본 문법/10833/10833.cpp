#include <iostream>
using namespace std;

int n;
int arr[2][101];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[j][i];
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[1][i] % arr[0][i];
    }

    cout << total << '\n';
    return 0;
}