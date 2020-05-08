#include <bits/stdc++.h>
using namespace std;

int arr[10];

int routes[4][25] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21},           // 여기까지가 첫번째 루트 (0~21) 22
    {0, 1, 2, 3, 4, 5, 22, 23, 24, 25, 26, 27, 20, 21},                                       // 여기까지가 두번째 루트 (0~13) 14
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 28, 29, 25, 26, 27, 20, 21},                           // 여기까지가 세번째 루트 (0~17) 17
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 30, 31, 32, 25, 26, 27, 20, 21}};  // 여기까지가 네번째 루트 (0~23) 24

int score[35] = {
    0, 2, 4, 6, 8, 10,
    12, 14, 16, 18, 20,
    22, 24, 26, 28, 30,
    32, 34, 36, 38, 40, 0,
    13, 16, 19,
    25, 30, 35,
    22, 24,
    28, 27, 26};

struct point {
    pair<int, int> first;
    pair<int, int> second;
    pair<int, int> third;
    pair<int, int> forth;
    int total;
};

int returnRoute(int index) {
    if (index == 5) {
        return 1;
    } else if (index == 10) {
        return 2;
    } else if (index == 15) {
        return 3;
    } else {
        return 0;
    }
}

bool isOut(pair<int, int> p) {
    int route = p.first;
    int index = p.second;

    if (route == 0) {
        if (index >= 21)
            return true;
    } else if (route == 1) {
        if (index >= 13)
            return true;
    } else if (route == 2) {
        if (index >= 17)
            return true;
    } else if (route == 3) {
        if (index >= 23)
            return true;
    }

    return false;
}

int returnNext(int route, int next) {
    if (route == 0) {
        if (next >= 21)
            return 21;
    } else if (route == 1) {
        if (next >= 13)
            return 13;
    } else if (route == 2) {
        if (next >= 17)
            return 17;
    } else {
        if (next >= 23)
            return 23;
    }

    return next;
}

bool isPause(int num, int move, point p) {
    if (num == 1) {
        int cmp_route = p.first.first;
        int cmp_index = returnNext(cmp_route, p.first.second + move);
        int cmp_value = routes[cmp_route][cmp_index];

        if (isOut({cmp_route, cmp_index})) {
            return false;
        }

        if (cmp_value == routes[p.second.first][p.second.second]) {
            return true;
        }

        if (cmp_value == routes[p.third.first][p.third.second]) {
            return true;
        }

        if (cmp_value == routes[p.forth.first][p.forth.second]) {
            return true;
        }
    }

    else if (num == 2) {
        int cmp_route = p.second.first;
        int cmp_index = returnNext(cmp_route, p.second.second + move);
        int cmp_value = routes[cmp_route][cmp_index];

        if (isOut({cmp_route, cmp_index})) {
            return false;
        }

        if (cmp_value == routes[p.first.first][p.first.second]) {
            return true;
        }

        if (cmp_value == routes[p.third.first][p.third.second]) {
            return true;
        }

        if (cmp_value == routes[p.forth.first][p.forth.second]) {
            return true;
        }
    }

    else if (num == 3) {
        int cmp_route = p.third.first;
        int cmp_index = returnNext(cmp_route, p.third.second + move);
        int cmp_value = routes[cmp_route][cmp_index];

        if (isOut({cmp_route, cmp_index})) {
            return false;
        }

        if (cmp_value == routes[p.first.first][p.first.second]) {
            return true;
        }

        if (cmp_value == routes[p.second.first][p.second.second]) {
            return true;
        }

        if (cmp_value == routes[p.forth.first][p.forth.second]) {
            return true;
        }
    }

    else if (num == 4) {
        int cmp_route = p.forth.first;
        int cmp_index = returnNext(cmp_route, p.forth.second + move);
        int cmp_value = routes[cmp_route][cmp_index];

        if (isOut({cmp_route, cmp_index})) {
            return false;
        }

        if (cmp_value == routes[p.first.first][p.first.second]) {
            return true;
        }

        if (cmp_value == routes[p.second.first][p.second.second]) {
            return true;
        }

        if (cmp_value == routes[p.third.first][p.third.second]) {
            return true;
        }
    }

    return false;
}

int max_value = 0;

int main(void) {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    queue<point> q;
    q.push({{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0});

    int cnt_index = 0;
    while (!q.empty()) {
        int q_size = q.size();
        int pre_value = max_value;

        while (q_size--) {
            point cnt = q.front();
            q.pop();

            if (max_value < cnt.total) {
                max_value = cnt.total;
            }

            if (cnt_index >= 10) {
                continue;
            }
            int move = arr[cnt_index];

            bool first_pause = isPause(1, move, cnt);
            bool second_pause = isPause(2, move, cnt);
            bool third_puase = isPause(3, move, cnt);
            bool forth_puase = isPause(4, move, cnt);

            // 첫번째 말 움직이기
            if (!isOut(cnt.first) && !first_pause) {
                int route = cnt.first.first;
                int next = returnNext(route, cnt.first.second + move);
                int score_index = routes[route][next];
                int next_total = cnt.total + score[score_index];

                if (route == 0) {
                    route = returnRoute(next);
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                }
            }

            // 두번째 말 움직이기
            if (!isOut(cnt.second) && !second_pause) {
                int route = cnt.second.first;
                int next = returnNext(route, cnt.second.second + move);
                int score_index = routes[route][next];
                int next_total = cnt.total + score[score_index];

                if (route == 0) {
                    route = returnRoute(next);
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                }
            }

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
        }
        cnt_index++;
    }

    cout << max_value << '\n';
    return 0;
}