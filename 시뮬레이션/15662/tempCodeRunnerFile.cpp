for (int j = 0; j < 8; j++) {
                    temp[j] = wheel[i][j];
                }

                for (int j = 0; j < 7; j++) {
                    wheel[i][j] = temp[j + 1];
                }
                wheel[i][7] = temp[0];