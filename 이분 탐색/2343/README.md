# 기타 레슨

![](2343.jpeg)

## 체점 현황

![](2343_score.png)

## 전체 소스 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;

bool cmp(int mid) {
    int cntM = 1;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] > mid) {
            return true;
        }

        sum += v[i];
        if (sum > mid) {
            sum = v[i];
            cntM++;
        }
    }

    return cntM > M;
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    v = vector<int>(N);
    int limit = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        limit += v[i];
    }

    int start, finish;
    start = 1;
    finish = limit;
    int answer = 0;

    while (start <= finish) {
        int mid = (start + finish) / 2;

        if (cmp(mid)) {
            start = mid + 1;
        } else {
            finish = mid - 1;
        }
    }

    cout << start << '\n';
    return 0;
}
```