# 백준 2442 - 별 찍기 - 5

https://www.acmicpc.net/problem/2442

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
```

## JAVA 코드
```java
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n - 1; j++) {
                System.out.print(' ');
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                System.out.print('*');
            }
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
    for j in range(i, n-1):
        print(' ', end='')
    for j in range(2*i+1):
        print('*', end='')
    print()
```

## python 숏 코드
```python
n = int(input())

for i in range(n):
    print(' '*(n-1-i) + '*'*(2*i+1))
```