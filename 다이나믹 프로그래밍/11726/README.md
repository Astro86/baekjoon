# 백준 11726 - 2xn 타일링

https://www.acmicpc.net/problem/11726

![](11726.jpeg)

## 전체 소스 코드
```cpp
#include <iostream>
using namespace std;

int n;
int arr[1001];

int tailing(int n) {
    if (n == 1 || n == 2 || arr[n] != 0) {
        return arr[n];
    }

    return arr[n] = (tailing(n - 1) + tailing(n - 2)) % 10007;
}

int main(void) {
    scanf("%d", &n);

    arr[1] = 1;
    arr[2] = 2;
    int num = tailing(n);

    printf("%d\n", num);
    return 0;
}
```
