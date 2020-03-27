#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

long long arr[MAX];
long long tree[4 * MAX];

long long sum(int left, int right, int node, int start, int finish) {
    if (left <= start && finish <= right) {
        return tree[node];
    }

    if (left > finish || right < start) {
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

long long init(int node, int start, int finish) {
    if (start == finish) {
        return tree[node] = arr[start];
    }

    int mid = (start + finish) / 2;
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, finish);
    return tree[node];
}

int main(void) {
    int n, m, k;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        } else {
            long long value = sum(b, c, 1, 1, n);
            cout << value << "\n";
        }
    }
    return 0;
}