# 11654 - 아스키코드

![](11654m.JPG)

## 문제 풀이

`ord()`함수는 입력받은 문자를 `아스키 코드`로 변환해주는 함수이다.

## python 코드
```python
a = input()
print(ord(a))
```
## cpp 코드
```cpp
#include <iostream>
using namespace std;

char c;

int main(void){
    cin>>c;

    printf("%d", c);
    return 0;
}
```