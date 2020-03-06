#include <iostream>
using namespace std;

int n;
int T;
int arr[11];

int main(void)
{
    cin >> T;

    while (T--) {
        cin >> n;

        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        for (int i = 4; i <= n; i++) {
            if (arr[i] == 0) {
                arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
            }
        }
        cout << arr[n] << '\n';
    }

    return 0;
}