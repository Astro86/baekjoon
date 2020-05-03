# 백준 1316 - 그룹 단어 체커

## 문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.


## 입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

## 출력
첫째 줄에 그룹 단어의 개수를 출력한다.


## 전체 소스 코드
```python
n = int(input())

result = n
for i in range(n):
    word = input()

    for j in range(1, len(word)):
        if(word.find(word[j-1]) > word.find(word[j])):
            result -= 1
            break
print(result)
```
뒤에 있는 단어의 index가  앞 단어의 index보다 작을 경우에는 뒤에 있는 단어가 먼저 나왔다는 의미이다.



## 전체 소스 코드 2
```python
cnt = 0

for i in range(int(input())):
    word = input()
    cnt += list(word) == sorted(word, key=word.find)

print(cnt)
```
`sorted(word, key=word.find)`를 사용하게 되면 word에서 찾아지는 char순대로 정렬이 된다.

## 입력
```
4
aba
abab
acbabc
a
```

## 출력
```
['a', 'a', 'b']
['a', 'a', 'b', 'b']
['a', 'a', 'c', 'c', 'b', 'b']
['a']
```

## 자바 소스 코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int num = n;

        while (n-- != 0) {
            boolean arr[] = new boolean[26];
            String word = br.readLine().trim();

            for (int i = 0; i < word.length(); i++) {
                if (arr[word.charAt(i) - 'a'] == false) {
                    arr[word.charAt(i) - 'a'] = true;
                    char cntChar = word.charAt(i);
                    while (i + 1 < word.length() && word.charAt(i + 1) == cntChar) {
                        i++;
                    }
                } else {
                    num--;
                    break;
                }
            }
        }

        System.out.println(num);
        br.close();
    }
}
```

## cpp 소스 코드
```cpp
#include <iostream>
#include <string>
using namespace std;

int T;
int num;

int main(void)
{
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool check[26];
        for (int i = 0; i < 26; i++) {
            check[i] = false;
        }

        int stringSize = s.size();
        bool isContinue = true;
        for (int i = 0; i < stringSize; i++) {
            char cntChar = s[i];
            int cntIndex = cntChar - 'a';

            if (check[cntIndex] == false) {
                check[cntIndex] = true;
                for (char c = cntChar; c == s[i]; s[i++]) {
                }
                i--;

            } else {
                isContinue = false;
            }
        }

        if (isContinue == true) {
            num++;
        }
    }

    cout << num << '\n';
    return 0;
}
```