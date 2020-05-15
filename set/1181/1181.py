n = int(input())

s = set()

for i in range(n):
    s.add(input())

s = sorted(sorted(s), key=len)
for a in s:
    print(a)
