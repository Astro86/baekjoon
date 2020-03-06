#include <iostream>
using namespace std;

int N, M;
int minEachPrice = 100000000;
int minPackagePrice = 10000000;

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;
        if (minPackagePrice > a) {
            minPackagePrice = a;
        }
        if (minEachPrice > b) {
            minEachPrice = b;
        }
    }

    int packageNum = N / 6;
    int eachNum = N % 6;

    if (minPackagePrice > minEachPrice * 6) {
        packageNum = 0;
        eachNum = N;
    } else {
        if (N < 6) {
            if (minPackagePrice < minEachPrice * eachNum) {
                packageNum = 1;
                eachNum = 0;
            }
        } else {
            if (minPackagePrice * (packageNum + 1) < minPackagePrice * packageNum + minEachPrice * eachNum) {
                packageNum++;
                eachNum = 0;
            }
        }
    }

    cout << minPackagePrice * packageNum + minEachPrice * eachNum << '\n';

    return 0;
}
