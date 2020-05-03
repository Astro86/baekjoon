def returnLOVENum(name):
    L = 0
    O = 0
    V = 0
    E = 0
    for c in name:
        if(c == 'L'):
            L += 1
        if(c == 'O'):
            O += 1
        if(c == 'V'):
            V += 1
        if(c == 'E'):
            E += 1

    return L, O, V, E


ohminsic = input()
n = int(input())
ohminsic_L, ohminsic_O, ohminsic_V, ohminsic_E = returnLOVENum(ohminsic)

name_list = []
for i in range(n):
    name_list.append(input())
name_list = sorted(name_list)


max_value = -1
max_name = ""
for name in name_list:
    L, O, V, E = returnLOVENum(name)

    value = ((ohminsic_L + L + ohminsic_O + O) *
             (ohminsic_L + L + ohminsic_V + V) *
             (ohminsic_L + L + ohminsic_E + E) *
             (ohminsic_O + O + ohminsic_V + V) *
             (ohminsic_O + O + ohminsic_E + E) *
             (ohminsic_V + V + ohminsic_E + E))

    value %= 100
    if(max_value < value):
        max_value = value
        max_name = name

print(max_name)
