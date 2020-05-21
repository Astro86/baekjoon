# 백준 13505 - XOR

## 전체 소스 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

// int arr[100001];
char binaryNumbers[100001][33];
int max_value = 0;

struct Trie {
    Trie* value[2];
    bool terminal;

    Trie() : terminal(false) {
        for (int i = 0; i < 2; i++) {
            value[i] = NULL;
        }
    };
    ~Trie() {
        for (int i = 0; i < 2; i++) {
            if (value[i] != NULL) {
                delete value[i];
            }
        }
    }

    void insert(const char* str) {
        if (*str == '\0') {
            terminal = true;
            return;
        }
        int cnt = *str - '0';
        if (value[cnt] == NULL) {
            value[cnt] = new Trie();
        }
        value[cnt]->insert(str + 1);
    }

    void query(char* str) {
        if (*str == '\0')
            return;
        int next = *str - '0';
        next ^= 1;
        if (value[next]) {
            *str = '1';
            return value[next]->query(str + 1);
        } else {
            *str = '0';
            return value[next ^ 1]->query(str + 1);
        }
    }
};
string makeBinaryNumber(int num) {
    string value;
    stack<int> st;
    while (num) {
        st.push(num % 2);
        num /= 2;
    }

    while (!st.empty()) {
        value += to_string(st.top());
        st.pop();
    }

    return value;
}

int main(void) {
    int n;
    cin >> n;

    Trie* trie = new Trie();
    for (int i = 0; i < n; i++) {
        // cin >> arr[i];
        int value;
        cin >> value;
        for (int j = 31; j >= 0; j--) {
            if (value % 2 == 1)
                binaryNumbers[i][j] = '1';
            else
                binaryNumbers[i][j] = '0';
            value = value >> 1;
        }
        binaryNumbers[i][32] = '\0';
        trie->insert(binaryNumbers[i]);
    }

    for (int i = 0; i < n; i++) {
        trie->query(binaryNumbers[i]);

        int decimalValue = 0;
        for (int j = 31; j >= 0; j--) {
            decimalValue += (binaryNumbers[i][j] - '0') * pow(2, 31 - j);
        }
        max_value = max(max_value, decimalValue);
    }
    cout << max_value << '\n';

    return 0;
}
```