if (map[i][j] == 0) {
                int blocks = 1;
                q.push({ i, j });
                map[i][j] = 2;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (0 <= ny && ny <= M && 0 <= nx && nx <= N) {
                            if (map[ny][nx] == 0) {
                                q.push({ ny, nx });
                                map[ny][nx] = 2;
                                blocks++;
                            }
                        }
                    }
                }
                area[areaNum++] = blocks;
            }