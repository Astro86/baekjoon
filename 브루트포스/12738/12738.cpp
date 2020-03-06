#include <algorithm>
#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 1000001

int n;
int arr[MAX];
int cache[MAX];

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    int length = 1;
    for (int i = 2; i <= n; i++) {
        int cntValue = arr[i];

        if (cntValue > cache[length]) {
            length++;
            cache[length] = cntValue;
        } else {
            int index = lower_bound(cache + 1, cache + length + 1, cntValue) - cache;
            cache[index] = cntValue;
        }
    }

    cout << length << '\n';
    return 0;
}