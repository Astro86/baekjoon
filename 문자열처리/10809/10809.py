alphabet_word = "abcdefghijklmnopqrstuvwxyz"
alphabet_dic = {}

for i in range(len(alphabet_word)):
    alphabet_dic[alphabet_word[i]] = -1


inputData = input()

for i in range(len(inputData)):
    for j in range(len(alphabet_word)):
        if inputData[i] == alphabet_word[j] and alphabet_dic[inputData[i]] == -1:
            alphabet_dic[inputData[i]] = i


for i in range(len(alphabet_dic)):
    print(str(alphabet_dic[alphabet_word[i]]) + " ", end='')
