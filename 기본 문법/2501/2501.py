n, m = map(int, input().split())

q = set()
for i in range(1, n+1):
    if(n % i == 0):
        q.add(n//i)
q = sorted(list(q))

if(m > len(q)):
    print(0)
else:
    print(q[m-1])
