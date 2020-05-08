n = int(input())
arr = list(map(int, input().split()))
score = 0
acc = 0
for i in range(n):
    if(arr[i] == 0):
        acc = 0
    else:
        acc += 1
        score += acc
print(score)
