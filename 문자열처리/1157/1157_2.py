n = input().upper()

arr = [0] * 26
for i in n:
    arr[ord(i) - ord('A')] += 1

max_num = max(arr)
if arr.count(max_num) >= 2:
    print('?')
else:
    print(chr(arr.index(max(arr))+ord('A')))
