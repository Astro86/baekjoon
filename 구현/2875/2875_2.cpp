#include <iostream>
using namespace std;

int N, M, K;

int main(void)
{
    cin >> N >> M >> K;

    while (K--) {
        if (N >= 2 * M) {
            N--;
        } else {
            M--;
        }
    }

    if (N >= 2 * M)
        cout << M << '\n';
    else
        cout << N / 2 << '\n';
    return 0;
}