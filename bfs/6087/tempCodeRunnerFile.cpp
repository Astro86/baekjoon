int north = cntY;
            while (north >= 0 && Map[north][cntX] != '*') {
                if (!check[north][cntX]) {
                    check[north][cntX] = true;
                    q.push({north, cntX});
                }
                north--;
            }

            int south = cntY;
            while (south < height && Map[south][cntX] != '*') {
                if (!check[south][cntX]) {
                    check[south][cntX] = true;
                    q.push({south, cntX});
                }
                south++;
            }

            int east = cntX;
            while (east < width && Map[cntY][east] != '*') {
                if (!check[cntY][east]) {
                    check[cntY][east] = true;
                    q.push({cntY, east});
                }
                east++;
            }

            int west = cntX;
            while (west >= 0 && Map[cntY][west] != '*') {
                if (!check[cntY][west]) {
                    check[cntY][west] = true;
                    q.push({cntY, west});
                }
                west--;
            }