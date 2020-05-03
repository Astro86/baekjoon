str = input()

dic = {}
for c in 'abcdefghijklmnopqrstuvwxyz':
    dic[c] = 0

for c in str:
    dic[c] += 1

for i in dic:
    print(dic[i], end=' ')
