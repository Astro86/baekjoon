#include <bits/stdc++.h>
using namespace std;

int arr[10];

int score[4][25] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},           // 여기까지가 첫번째 루트 (0~21)  21
    {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, 0},                                           // 여기까지가 두번째 루트 (0~13) 13
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, 0},                           // 여기까지가 세번째 루트 (0~17) 17
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, 0}};  // 여기까지가 네번째 루트 (0~23) 23

struct point {
    pair<int, int> first;
    pair<int, int> second;
    pair<int, int> third;
    pair<int, int> forth;
    int total;
};

int switchIndex(int index) {
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
        if (index > 20)
            return true;
    } else if (route == 1) {
        if (index > 12)
            return true;
    } else if (route == 2) {
        if (index > 16)
            return true;
    } else {
        if (index > 22)
            return true;
    }

    return false;
}

int returnNext(pair<int, int> p, int move) {
    int route = p.first;
    int index = p.second;

    if (route == 0) {
        if (index + move > 20)
            return 21;
    } else if (route == 1) {
        if (index + move > 12)
            return 13;
    } else if (route == 2) {
        if (index + move > 16)
            return 17;
    } else {
        if (index + move > 22)
            return 23;
    }

    return index + move;
}

bool isPause(int num, int move, point p) {
    if (num == 1) {
        int target_route = p.first.first;
        int target_index = p.first.second + move;

        if (isOut({target_route, target_index})) {
            return false;
        }

        if (target_route == p.second.first && target_index == p.second.second) {
            return true;
        }
        if (target_route == p.third.first && target_index == p.third.second) {
            return true;
        }
        if (target_route == p.forth.first && target_index == p.forth.second) {
            return true;
        }
    }

    if (num == 2) {
        int target_route = p.second.first;
        int target_index = p.second.second + move;

        if (isOut({target_route, target_index})) {
            return false;
        }

        if (target_route == p.first.first && target_index == p.first.second) {
            return true;
        }
        if (target_route == p.third.first && target_index == p.third.second) {
            return true;
        }
        if (target_route == p.forth.first && target_index == p.forth.second) {
            return true;
        }
    }

    if (num == 3) {
        int target_route = p.third.first;
        int target_index = p.third.second + move;

        if (isOut({target_route, target_index})) {
            return false;
        }

        if (target_route == p.second.first && target_index == p.second.second) {
            return true;
        }
        if (target_route == p.first.first && target_index == p.first.second) {
            return true;
        }
        if (target_route == p.forth.first && target_index == p.forth.second) {
            return true;
        }
    }

    if (num == 4) {
        int target_route = p.forth.first;
        int target_index = p.forth.second + move;

        if (isOut({target_route, target_index})) {
            return false;
        }

        if (target_route == p.second.first && target_index == p.second.second) {
            return true;
        }
        if (target_route == p.third.first && target_index == p.third.second) {
            return true;
        }
        if (target_route == p.first.first && target_index == p.first.second) {
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

            max_value = max(max_value, cnt.total);

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
                int next = returnNext(cnt.first, move);
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                }
            }

            // 두번째 말 움직이기
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

            // // 세번째 말 움직이기
            // if (!isOut(cnt.third) && !third_puase) {
            //     int route = cnt.third.first;
            //     int next = returnNext(cnt.third, move);
            //     int next_total = cnt.total + score[route][next];

            //     if (route == 0) {
            //         route = switchIndex(next);
            //         q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
            //     } else {
            //         q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
            //     }
            // }

            // 네번째 말 움직이기
            // if (!isOut(cnt.forth) && !forth_puase) {
            //     int route = cnt.forth.first;
            //     int next = returnNext(cnt.forth, move);
            //     int next_total = cnt.total + score[route][next];

            //     if (route == 0) {
            //         route = switchIndex(next);
            //         q.push({cnt.first, cnt.second, cnt.third, {route, next}, next_total});
            //     } else {
            //         q.push({cnt.first, cnt.second, cnt.third, {route, next}, next_total});
            //     }
            // }
        }
        cout << max_value << " " << max_value - pre_value << '\n';
        cnt_index++;
    }

    cout << max_value << '\n';
    return 0;
}