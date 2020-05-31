n, m = map(int, input().split())

matrix = [[0]*m for _ in range(n)]
check = [[False]*m for _ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n):
    row = input()
    for j in range(m):
        matrix[i][j] = int(row[j])

queue = []
queue.append((0, 0))
check[0][0] = True
num = 0

while queue:
    num += 1
    q_size = len(queue)

    while(q_size):
        y, x = queue.pop(0)

        if y == n-1 and x == m-1:
            print(num)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if(0 <= ny < n and 0 <= nx < m):
                if(matrix[ny][nx] == 1 and check[ny][nx] == False):
                    check[ny][nx] = True
                    queue.append((ny, nx))

        q_size -= 1
