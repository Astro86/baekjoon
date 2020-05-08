date = int(input())
arr = map(int, input().split())
num = 0
for i in arr:
    if(date == i):
        num += 1
print(num)
