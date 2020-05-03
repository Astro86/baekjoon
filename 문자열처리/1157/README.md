# 백준 1157 - 단어 공부

## 문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.


## 입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

## 출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

## 파이썬 소스 코드
```python
n = input().upper()

arr = [0] * 26
for i in n:
    arr[ord(i) - ord('A')] += 1

max_num = max(arr)
if arr.count(max_num) >= 2:
    print('?')
else:
    print(chr(arr.index(max(arr))+ord('A')))
```

## 자바 소스 코드
```java
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine().toUpperCase();

        int check[] = new int[26];
        for (int i = 0; i < s.length(); i++) {
            check[s.charAt(i) - 'A']++;
        }

        int max_num = 0;
        int num = 0;
        int index = 0;

        for (int i = 0; i < 26; i++) {
            if (max_num < check[i]) {
                max_num = check[i];
            }
        }

        for (int i = 0; i < 26; i++) {
            if (max_num == check[i]) {
                index = i;
                num++;
            }
        }

        if (num >= 2) {
            System.out.println('?');
        } else {
            System.out.println((char) ('A' + index));
        }

        br.close();
    }
}
```