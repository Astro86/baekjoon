n = int(input())

dic = {}

for i in range(n):
    name, command = input().split()
    if(command == "enter"):
        dic[name] = True
    else:
        del dic[name]

dic = sorted(dic, reverse=True)
for i in dic:
    print(i)
