def bfs(start):
    queue = [start]
    bfs_check = [start]

    while queue:
        cnt_node = queue.pop(0)

        for next_node in range(len(matrix[cnt_node])):
            if(matrix[cnt_node][next_node] == 1 and next_node not in bfs_check):
                bfs_check.append(next_node)
                queue.append(next_node)

    return bfs_check


def dfs(cnt_node):
    dfs_check.append(cnt_node)

    for next_node in range(len(matrix[cnt_node])):
        if(matrix[cnt_node][next_node] == 1 and next_node not in dfs_check):
            dfs(next_node)


N, M, V = map(int, input().split())
matrix = [[0] * (N+1) for i in range(N+1)]
dfs_check = []

for i in range(M):
    point = list(map(int, input().split()))
    matrix[point[0]][point[1]] = 1
    matrix[point[1]][point[0]] = 1

dfs(V)
print(*dfs_check)
print(*bfs(V))
