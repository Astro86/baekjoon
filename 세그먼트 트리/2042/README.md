# 백준 2042 - 구간 합 구하기

## 문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.


## 입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.
입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

## 출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

## 전체 소스 코드
```python
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
long long arr[1000001];
long long tree[3000001];

long long init(int node, int start, int finish) {
    if (start == finish) {
        return tree[node] = arr[start];
    }

    int mid = (start + finish) / 2;
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, finish);
    return tree[node];
}

long long sum(int left, int right, int node, int start, int finish) {
    if (left <= start && finish <= right) {
        return tree[node];
    }

    if (right < start || left > finish) {
        return 0;
    }

    int mid = (start + finish) / 2;
    return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, finish);
}

void update(int node, int start, int finish, int value, int diff) {
    if (start <= value && value <= finish) {
        tree[node] += diff;
    } else {
        return;
    }

    if (start == finish) {
        return;
    }

    int mid = (start + finish) / 2;
    update(node * 2, start, mid, value, diff);
    update(node * 2 + 1, mid + 1, finish, value, diff);
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        } else {
            long long value = sum(b, c, 1, 1, N);
            cout << value << '\n';
        }
    }
    return 0;
}
```