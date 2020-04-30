str = input()

JOI_num = 0
IOI_num = 0
for i in range(len(str)-2):
    if(str[i:i+3] == 'JOI'):
        JOI_num += 1
    if(str[i:i+3] == 'IOI'):
        IOI_num += 1

print(JOI_num)
print(IOI_num)
