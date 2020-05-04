def isAllI():
    for i in range(1, N+1):
        cnt_node = i

        for j in range(1, H+1):
            if(ladder[j][cnt_node] == 1):
                cnt_node = cnt_node+1
            elif(ladder[j][cnt_node-1] == 1):
                cnt_node = cnt_node-1

        if(cnt_node != i):
            return False
    return True


def dfs(height, num):
    if(num > 3):
        return

    if(isAllI()):
        global min_value
        if(min_value > num):
            min_value = num
        return

    for i in range(height, H+1):
        for j in range(1, N+1):
            if(ladder[i][j] == 0 and ladder[i][j-1] == 0 and ladder[i][j+1] == 0):
                ladder[i][j] = 1
                dfs(i, num+1)
                ladder[i][j] = 0


N, M, H = map(int, input().split())

ladder = [[0] * (N+5) for _ in range(H+5)]
check = [[0] * (N+5) for _ in range(H+5)]

min_value = 987654321


for i in range(M):
    a, b = map(int, input().split())
    ladder[a][b] = 1

dfs(1, 0)

if(min_value == 987654321):
    print(-1)
else:
    print(min_value)
