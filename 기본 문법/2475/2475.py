arr = list(map(int, input().split()))
total = 0
for i in arr:
    total += i*i
print(total % 10)
