#include <iostream>
using namespace std;

int N, M, K;
int team;

int main(void)
{
    cin >> N >> M >> K;

    int N2 = N / 2;
    int remainder = N % 2;
    K -= remainder;

    while (K--) {
        if (N2 > M) {
            N2--;
        } else {
            M--;
        }
    }

    if (N2 > M) {
        team = M;
    } else {
        team = N2;
    }
    cout << team << '\n';
}