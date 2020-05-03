a = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
s = input()
for t in a:
    s = s.replace(t, "*")

print(len(s))
