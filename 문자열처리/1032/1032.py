n = int(input())

commands = []
for i in range(n):
    commands.append(input())

cmp_comamnd = list(commands[0])
for cmd in commands:
    for i in range(len(cmp_comamnd)):
        if(cmp_comamnd[i] != cmd[i]):
            cmp_comamnd[i] = '?'
print(''.join(cmp_comamnd))
