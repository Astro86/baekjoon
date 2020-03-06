#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

vector<int> v;
int n;

int main(void)
{
    cin >> n;

    v = vector<int>(n + 10, INF);
    v[1] = 0;

    for (int i = 1; i <= n; i++) {

        if (i + 1 <= n && v[i + 1] > v[i] + 1) {
            v[i + 1] = v[i] + 1;
        }

        if (2 * i <= n && v[2 * i] > v[i] + 1) {
            v[2 * i] = v[i] + 1;
        }

        if (3 * i <= n && v[3 * i] > v[i] + 1) {
            v[3 * i] = v[i] + 1;
        }
    }
    cout << v[n] << '\n';
    return 0;
}