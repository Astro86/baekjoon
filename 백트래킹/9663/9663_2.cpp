#include <iostream>
using namespace std;

int n;
int row[16];
int total;

bool isPossible(int cnt_row_index) {
    for (int i = 0; i < cnt_row_index; i++) {
        if (row[i] == row[cnt_row_index] || abs(row[i] - row[cnt_row_index]) == cnt_row_index - i)
            return false;
    }

    return true;
}

void nqeen(int cnt_row_index) {
    if (cnt_row_index == n) {
        total++;
        return;
    }

    for (int i = 0; i < n; i++) {
        row[cnt_row_index] = i;
        if (isPossible(cnt_row_index)) {
            nqeen(cnt_row_index + 1);
        }
    }
}

int main(void) {
    cin >> n;
    nqeen(0);
    cout << total << '\n';
    return 0;
}