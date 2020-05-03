# 백준 10809 - 알파벳 찾기

## 문제
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.


## 입력
첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

## 출력
각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.

## python 코드 - 문자 체크하는 방법
```python
alphabet_word = "abcdefghijklmnopqrstuvwxyz"
alphabet_dic = {}

for i in range(len(alphabet_word)):
    alphabet_dic[alphabet_word[i]] = -1


inputData = input()

for i in range(len(inputData)):
    for j in range(len(alphabet_word)):
        if inputData[i] == alphabet_word[j] and alphabet_dic[inputData[i]] == -1:
            alphabet_dic[inputData[i]] = i


for i in range(len(alphabet_dic)):
    print(str(alphabet_dic[alphabet_word[i]]) + " ", end='')
```

## python 코드 - 딕셔너리를 사용하는 방법
```python
alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet_dic = {}

for i in range(len(alphabet)):
    alphabet_dic[alphabet[i]] = -1

s = input()

for i in range(len(s)):
    if alphabet_dic[s[i]] == -1:
        alphabet_dic[s[i]] = i

for i in range(len(alphabet)):
    print(alphabet_dic[alphabet[i]], end=" ")
```