n, m = map(int, input().split())

q = set()
for i in range(1, n+1):
    q.add(6//i)
q = sorted(list(q))

if(m > len(q)-1):
    print(0)
else:
    print(q[m-1])
