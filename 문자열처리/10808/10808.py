str = input()

arr = [0] * 26
for c in str:
    arr[ord(c) - ord('a')] += 1
for i in arr:
    print(i, end=' ')
