#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
int J, A;
char arr[MAX];
bool check[MAX];

int main(void) {
    cin >> J >> A;

    for (int i = 1; i <= J; i++) {
        cin >> arr[i];
    }

    int num = 0;
    for (int i = 0; i < A; i++) {
        char size;
        int index;
        cin >> size >> index;
        int cntSize = arr[index];

        if (check[index]) {
            continue;
        }

        if (size == 'S') {
            check[index] = true;
            num++;
        } else if (size == 'M') {
            if (cntSize == 'M' || cntSize == 'L') {
                check[index] = true;
                num++;
            }
        } else {
            if (cntSize == 'L') {
                check[index] = true;
                num++;
            }
        }
    }

    cout << num << '\n';
    return 0;
}