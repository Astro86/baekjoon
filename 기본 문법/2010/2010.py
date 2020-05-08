import sys
n = int(sys.stdin.readline())

total = 0
for i in range(n):
    total += int(sys.stdin.readline())

total -= (n-1)
print(total)
