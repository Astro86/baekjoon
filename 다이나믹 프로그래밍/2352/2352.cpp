#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;

int main(void)
{
    cin >> n;
    int connection[n + 1];
    int cache[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> connection[i];
    }

    cache[1] = connection[1];
    int length = 1;
    for (int i = 2; i <= n; i++) {

        if (cache[length] < connection[i]) {
            length += 1;
            cache[length] = connection[i];
        } else {
            int index = lower_bound(cache + 1, cache + length + 1, connection[i]) - cache;
            cache[index] = connection[i];
        }
    }

    cout << length << '\n';

    return 0;
}