alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet_dic = {}

for i in range(len(alphabet)):
    alphabet_dic[alphabet[i]] = -1

s = input()

for i in range(len(s)):
    if alphabet_dic[s[i]] == -1:
        alphabet_dic[s[i]] = i

for i in range(len(alphabet)):
    print(alphabet_dic[alphabet[i]], end=" ")
