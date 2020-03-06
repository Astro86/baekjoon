#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 40004

int n;
// int arr[MAX];
// int cache[MAX];

int main(void)
{
    cin >> n;

    vector<int> arr(MAX);
    vector<int> cache;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cache.push_back(arr[0]);
    for (int i = 1; i <= n; i++) {

        if (cache.back() < arr[i]) {
            cache.push_back(arr[i]);
        } else {
            int index = lower_bound(cache.begin(), cache.end(), arr[i]) - cache.begin();
            cache[index] = arr[i];
        }
    }

    cout << cache.size() << '\n';
    return 0;
}