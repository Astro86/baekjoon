#include <iostream>
using namespace std;

int N, M, K;
int team;

int main(void)
{
    cin >> N >> M >> K;

    while (K--) {
        if (N > 2 * M) {
            N--;
        } else {
            M--;
        }
    }

    if (N > 2 * M) {
        team = M;
    } else {
        team = N / 2;
    }
    cout << team << '\n';
}