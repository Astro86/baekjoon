// 세번째 말 움직이기
            if (!isOut(cnt.third) && !third_puase) {
                int route = cnt.third.first;
                int next = returnNext(route, cnt.third.second + move);
                int score_index = routes[route][next];
                int next_total = cnt.total + score[score_index];

                if (route == 0) {
                    route = returnRoute(next);
                    q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
                } else {
                    q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
                }
            }

            // 네번째 말 움직이기
            if (!isOut(cnt.forth) && !forth_puase) {
                int route = cnt.forth.first;
                int next = returnNext(route, cnt.forth.second + move);
                int score_index = routes[route][next];
                int next_total = cnt.total + score[score_index];

                if (route == 0) {
                    route = returnRoute(next);
                    q.push({cnt.first, cnt.second, cnt.third, {route, next}, next_total});
                } else {
                    q.push({cnt.first, cnt.second, cnt.third, {route, next}, next_total});
                }
            }