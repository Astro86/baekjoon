n = input()

total = 0
for i in range(int(n)):
    student, apple = map(int, input().split())
    total += apple % student

print(total)