#include <bits/stdc++.h>
using namespace std;

int heap[10001];

void postOrder(int index) {
    if (!heap[index]) {
        return;
    }

    postOrder(index * 2);
    postOrder(index * 2 + 1);
    cout << heap[index] << '\n';
}

void makeHeap(int value) {
    int index = 1;
    while (heap[index]) {
        if (heap[index] > value) {
            index *= 2;
        } else {
            index = (index * 2) + 1;
        }
    }
    heap[index] = value;
}

int main(void) {
    int value;
    while (scanf("%d", &value) != -1) {
        makeHeap(value);
    }

    postOrder(1);
}