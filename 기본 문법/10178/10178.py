n = int(input())
for i in range(n):
    num, m = map(int, input().split())
    value = num//m
    r = num % m
    print(f"You get {value} piece(s) and your dad gets {r} piece(s).")
