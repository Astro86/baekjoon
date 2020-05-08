n = int(input())
for i in range(n):
    print(' '*(n-1-i), end='')
    print('*'*(i+1))
for i in range(n-1):
    print(' '*(i+1), end='')
    print('*'*(n-1-i))
