arr = []
for i in range(1, 1001):
    if(len(arr) > 1000):
        break
    for j in range(i):
        arr.append(i)

n, m = map(int, input().split())
sum = 0
for i in range(n-1, m):
    sum += arr[i]
print(sum)
