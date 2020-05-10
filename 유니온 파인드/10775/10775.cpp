#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
int parent[MAX];
int g, p;

int find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void merge(int a, int b) {
    int setA = find(a);
    int setB = find(b);

    if (setA != setB) {
        parent[setA] = setB;
    }
}

int main(void) {
    cin >> g >> p;
    for (int i = 1; i <= g; i++) {
        parent[i] = i;
    }

    int num = 0;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;

        if (!find(x))
            break;
        num++;
        int c = find(x);
        merge(c, c - 1);
    }

    cout << num << '\n';
}