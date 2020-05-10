#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 40004

int n;
int arr[MAX];
int cache[MAX];

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    int lastIndex = 1;
    for (int i = 2; i <= n; i++) {
        if (cache[lastIndex] < arr[i]) {
            lastIndex++;
            cache[lastIndex] = arr[i];
        } else {
            int index = lower_bound(cache + 1, cache + lastIndex + 1, arr[i]) - cache;
            cache[index] = arr[i];
        }
    }

    cout << lastIndex << '\n';
    return 0;
}