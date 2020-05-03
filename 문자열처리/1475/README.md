# 백준 1475 - 방 번호

## 문제
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)


## 입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.

## 출력
첫째 줄에 필요한 세트의 개수를 출력한다.

## 전체 소스 코드
```python
n = input()

arr = [0] * 10

set = 0
six_nine = 0
for c in n:
    if(c == '9' or c == '6'):
        six_nine += 1
    else:
        arr[int(c)] += 1

if(six_nine % 2 == 1):
    six_nine /= 2
    six_nine += 1
else:
    six_nine /= 2

set = max(arr)

print(max(set, int(six_nine)))
```

## cpp 코드
```cpp
#include <iostream>
#include <string>
using namespace std;

string N;
int arr[10];

int main(void)
{
    cin >> N;

    int string_size = N.size();
    for (int i = 0; i < string_size; i++) {
        char cntNum = N[i];
        arr[cntNum - '0']++;
    }

    int NineSix = arr[6] + arr[9];
    if (NineSix % 2 == 1) {
        arr[6] = NineSix / 2 + 1;
        arr[9] = NineSix / 2 + 1;
    } else {
        arr[6] = NineSix / 2;
        arr[9] = NineSix / 2;
    }

    int maxNum = 0;
    for (int i = 0; i < 10; i++) {
        if (maxNum < arr[i]) {
            maxNum = arr[i];
        }
    }

    cout << maxNum << '\n';
}
```