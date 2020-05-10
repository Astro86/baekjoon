# 백준 11053 - 가장 긴 증가하는 부분 수열

![](11053.jpeg)

## 전체 소스 코드
```cpp
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1001

int n;

int main(void) {
    cin >> n;

    int arr[MAX];
    int cache[MAX];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    int cache_length = 1;
    for (int i = 2; i <= n; i++) {
        if (cache[cache_length] < arr[i]) {
            cache_length++;
            cache[cache_length] = arr[i];
        } else {
            int index = lower_bound(cache + 1, cache + cache_length + 1, arr[i]) - cache;
            cache[index] = arr[i];
        }
    }

    cout << cache_length << '\n';
    return 0;
}
```