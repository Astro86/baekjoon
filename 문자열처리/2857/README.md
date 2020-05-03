# 백준 2857 - FBI

## 문제
5명의 요원 중 FBI 요원을 찾는 프로그램을 작성하시오.
FBI요원은 요원의 첩보원명에 FBI가 들어있다.


## 입력
5개 줄에 요원의 첩보원명이 주어진다. 첩보원명은 알파벳 대문자, 숫자 0~9, 대시 (-)로만 이루어져 있으며, 최대 10글자이다.

## 출력
첫째 줄에 FBI 요원을 출력한다. 이때, 해당하는 요원이 몇 번째 입력인지를 공백으로 구분하여 출력해야 하며, 오름차순으로 출력해야 한다. 만약 FBI 요원이 없다면 "HE GOT AWAY!"를 출력한다.

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int num = 0;
    string code_name;

    for (int i = 0; i < 5; i++) {
        getline(cin, code_name, '\n');

        if (code_name.find("FBI") != string::npos) {
            cout << i + 1 << ' ';
            num++;
        }
    }

    if (num == 0)
        cout << "HE GOT AWAY!" << '\n';

    return 0;
}
```

## python 코드
```python
isFBI = False

for i in range(5):
    code_name = input()
    if(code_name.find("FBI") != -1):
        print(i+1, end=' ')
        isFBI = True

if(isFBI == False):
    print("HE GOT AWAY!")
```

## JAVA 코드

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean isContain = false;

        for (int i = 1; i <= 5; i++) {
            String code_name = br.readLine();

            if (code_name.contains("FBI")) {
                isContain = true;
                System.out.print(Integer.toString(i) + ' ');
            }
        }

        if (!isContain) {
            System.out.println("HE GOT AWAY!");
        }

        br.close();
    }
}
```