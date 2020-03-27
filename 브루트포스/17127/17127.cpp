#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];
int check[10];
int maxValue = 0;

void nCr(int num, int index) {
    if (num == n - 3) {
        int sum = 1;
        for (int i = 0; i < n; i++) {
            if (check[i] == true) {
                sum *= arr[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i] == false) {
                sum += arr[i];
            }
        }

        maxValue = max(maxValue, sum);
        return;
    }

    for (int i = index; i < n; i++) {
        if (check[i] == false) {
            check[i] = true;
            nCr(num + 1, i + 1);
            check[i] = false;
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    nCr(0, 0);

    cout << maxValue << '\n';
    return 0;
}