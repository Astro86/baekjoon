#include <iostream>
using namespace std;

bool check[2000];
int n, k;

int main(void)
{
    cin >> n >> k;

    int num = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            if (check[i * j] == false) {
                check[i * j] = true;
                num++;
            }

            if (num == k) {
                cout << j * i << '\n';
                return 0;
            }
        }
    }

    return 0;
}