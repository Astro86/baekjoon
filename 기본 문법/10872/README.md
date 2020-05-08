# 백준 10872 - 팩토리얼

## 문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.


## 입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

## 출력
첫째 줄에 N!을 출력한다.

## 파이썬 코드
```python
n = int(input())
total = 1
for i in range(1, n+1):
    total *= i
print(total)
```
