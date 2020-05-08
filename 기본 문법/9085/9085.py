test_case = int(input())
for i in range(test_case):
    n = input()
    arr = map(int, input().split())
    total = 0
    for value in arr:
        total += value
    print(total)
