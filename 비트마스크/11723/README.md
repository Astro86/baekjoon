# 백준 11723 - 집합

![](11723.jpeg)

## 전체 소스 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int M;
int bit;
int value;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> M;
    while (M--) {
        string op;
        cin >> op;
        if (op == "add") {
            cin >> value;

            // or 연산
            bit |= (1 << value);

        } else if (op == "remove") {
            cin >> value;

            // and 연산, not 연산
            bit &= ~(1 << value);

        } else if (op == "check") {
            cin >> value;

            // and 연산
            if (bit & (1 << value))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';

        } else if (op == "toggle") {
            cin >> value;

            // xor 연산
            bit ^= (1 << value);
        } else if (op == "all") {
            bit = (1 << 21) - 1;
        } else {
            bit = 0;
        }
    }
    return 0;
}
```