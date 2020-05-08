arr = []
total = 0
for i in range(7):
    value = int(input())
    if(value % 2 == 1):
        arr.append(value)
        total += value
if(total == 0):
    print(-1)
else:
    print(total)
    print(min(arr))
