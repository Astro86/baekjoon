#include <iostream>
using namespace std;

bool arr[1001];
int n;
int num;

int main(void)
{
    cin >> n;

    if (n < 100) {
        num = n;
    } else {
        num = 99;

        for (int i = 100; i <= n; i++) {
            int cnt = i;
            int d1, d2;
            if (i == 1000)
                continue;
            int a1 = cnt % 10;
            cnt /= 10;
            int a2 = cnt % 10;
            cnt /= 10;
            int a3 = cnt % 10;

            d1 = a2 - a1;
            d2 = a3 - a2;

            if (d1 == d2) {
                num++;
            }
        }
    }

    cout << num << '\n';
    return 0;
}