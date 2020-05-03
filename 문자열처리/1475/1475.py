n = input()

arr = [0] * 10

set = 0
six_nine = 0
for c in n:
    if(c == '9' or c == '6'):
        six_nine += 1
    else:
        arr[int(c)] += 1

if(six_nine % 2 == 1):
    six_nine /= 2
    six_nine += 1
else:
    six_nine /= 2

set = max(arr)

print(max(set, int(six_nine)))
