n = int(input())
for i in range(1, n+1):
    print('*'*i, end='')
    print(' '*(2*(n-i)), end='')
    print('*'*i)

for i in range(1, n):
    print('*'*(n-i), end='')
    print(' '*(2*(i)), end='')
    print('*'*(n-i))
