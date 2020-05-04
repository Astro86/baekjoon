if (!isOut(cnt.second) && !second_pause) {
                int route = cnt.second.first;
                int next = returnNext(cnt.second, move);
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                }
            }