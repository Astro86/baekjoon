#include <iostream>
using namespace std;

int col[15];
int n;
int result;

bool promising(int i) {
    for (int j = 0; j < i; j++) {
        if (col[j] == col[i] || abs(col[i] - col[j]) == i - j)
            return false;
    }
    return true;
}

void nqeen(int i) {
    if (i == n)
        result++;
    else {
        for (int j = 0; j < n; j++) {
            col[i] = j;
            if (promising(i))
                nqeen(i + 1);
        }
    }
}

int main(void) {
    cin >> n;
    nqeen(0);
    cout << result << endl;
    return 0;
}