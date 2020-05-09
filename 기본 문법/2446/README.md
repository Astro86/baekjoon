# 백준 2446 - 별 찍기 - 9

## 문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.


## 입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

## 출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

## 파이썬 코드
```python
n = int(input())
for i in range(n):
    print(' '*i, end='')
    print('*'*(2*(n-i)-1))
for i in range(1, n):
    print(' '*(n-i-1), end='')
    print('*'*(2*i + 1))
```