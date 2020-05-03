n = int(input())

result = n
for i in range(n):
    word = input()

    for j in range(1, len(word)):
        if(word.find(word[j-1]) > word.find(word[j])):
            result -= 1
            break
print(result)
