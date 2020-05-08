# 백준 9295 - 주사위

## 문제
오늘은 갑자기 주사위를 던지고 싶다.
그런데 코딩도 하고 싶다.
그럼 같이할까?


## 입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 주사위를 두 번 던져 나온 두 수를 입력한다.

## 출력
각 테스트 케이스마다 "Case x: "를 출력한 다음, 주사위를 두 번 던져 나온 두 수의 합을 출력한다. 테스트 케이스 번호(x)는 1부터 시작한다.

## 파이썬 코드
```python
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(f'Case {i+1}: {a+b}')
```

## 파이썬 코드
```python
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print('Case {}: {}'.format(i+1, a+b))
```