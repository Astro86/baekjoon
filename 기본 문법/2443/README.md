# 백준 2443 - 별 찍기 - 6

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << '*';
        }
        cout << endl;
    }
}
```

## JAVA 코드
```java
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n - 1; j++)
                System.out.print(' ');
            for (int j = 0; j < 2 * i + 1; j++)
                System.out.print('*');
            System.out.println();
        }

        sc.close();
    }
}
```

## python 코드
```python
n = int(input())

for i in range(n):
    print(' '*i + '*'*(2*(n-i-1)+1))
```