    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            maze[z][j][1 - i] = maze[z][3 + i][j];
        }
    }
