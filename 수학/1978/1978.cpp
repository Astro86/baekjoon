#include <iostream>
using namespace std;

int n;
int arr[101];
bool check[1001];
int num;

int main(void)
{
    check[0] = true;
    check[1] = true;
    for (int i = 2; i * i <= 1000; i++) {
        for (int j = 2; i * j <= 1000; j++) {
            check[i * j] = true;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (check[arr[i]] == false) {
            num++;
        }
    }

    cout << num << '\n';
    return 0;
}