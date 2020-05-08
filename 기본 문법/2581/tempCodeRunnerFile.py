check = [False]*10001

for i in range(2, 10001):
    if(i*i > 10000):
        break
    for j in range(2*i, 10001, i):
        check[j] = True

l = []
sum = 0
n = int(input())
m = int(input())
for i in range(n, m+1):
    if(check[i] == False):
        l.append(i)
        sum += i
if(len(l) != 0):
    print(sum)
    print(l[0])
else:
    print(-1)
