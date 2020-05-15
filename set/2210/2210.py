map = [['0']*5 for _ in range(5)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

s = set()


def dfs(y, x, depth, str):
    if(depth == 6):
        global s
        s.add(str)
        return

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if(0 > ny or ny >= 5 or 0 > nx or nx >= 5):
            continue
        dfs(ny, nx, depth+1, str + map[ny][nx])


for i in range(5):
    map[i] = input().split()

for i in range(5):
    for j in range(5):
        dfs(i, j, 1, map[i][j])

print(len(s))
