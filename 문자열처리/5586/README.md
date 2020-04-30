# 백준 5586 - JOI와 IOI

## 문제
입력으로 주어지는 문자열에서 연속으로 3개의 문자가 JOI 또는 IOI인 곳이 각각 몇 개 있는지 구하는 프로그램을 작성하시오. 문자열은 알파벳 대문자로만 이루어져 있다. 예를 들어, 아래와 같이 "JOIOIOI"에는 JOI가 1개, IOI가 2개 있다.



## 입력
첫째 줄에 알파벳 10000자 이내의 문자열이 주어진다.

## 출력
첫째 줄에 문자열에 포함되어 있는 JOI의 개수, 둘째 줄에 IOI의 개수를 출력한다.

## 파이썬 코드
```python
str = input()

JOI_num = 0
IOI_num = 0
for i in range(len(str)-2):
    if(str[i:i+3] == 'JOI'):
        JOI_num += 1
    if(str[i:i+3] == 'IOI'):
        IOI_num += 1

print(JOI_num)
print(IOI_num)
```

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    cin >> s;

    int JOI_num = 0;
    int IOI_num = 0;

    for (int i = 0; i < s.size() - 2; i++) {
        string temp = s.substr(i, 3);
        if (temp == "JOI") {
            JOI_num++;
        }

        if (temp == "IOI") {
            IOI_num++;
        }
    }

    cout << JOI_num << '\n';
    cout << IOI_num << '\n';
    return 0;
}
```

## JAVA 코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int JOI_num = 0;
        int IOI_num = 0;

        for (int i = 0; i < s.length() - 2; i++) {
            String subString = s.substring(i, i + 3);

            if (subString.equals("JOI")) {
                JOI_num++;
            }

            if (subString.equals("IOI")) {
                IOI_num++;
            }
        }

        System.out.println(JOI_num);
        System.out.println(IOI_num);

        br.close();
    }
}
```