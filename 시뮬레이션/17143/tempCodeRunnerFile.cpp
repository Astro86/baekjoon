for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (grid[i][j].size != 0) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << endl;
        }
        cout << endl;