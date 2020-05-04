#include <bits/stdc++.h>
using namespace std;

int arr[10];

int score[4][25] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},           // 여기까지가 첫번째 루트 (0~20)  21
    {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40},                                           // 여기까지가 두번째 루트 (0~13) 13
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40},                           // 여기까지가 세번째 루트 (0~17) 17
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40}};  // 여기까지가 네번째 루트 (0~23) 23

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

bool isOut(pair<int, int> p, int move) {
    int route = p.first;
    int index = p.second;

    if (route == 0) {
        if (index + move >= 21)
            return true;
    } else if (route == 1) {
        if (index + move >= 13)
            return true;
    } else if (route == 2) {
        if (index + move >= 17)
            return true;
    } else {
        if (index + move >= 23)
            return true;
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

        while (q_size--) {
            point cnt = q.front();
            q.pop();

            max_value = max(max_value, cnt.total);

            if (cnt_index >= 10) {
                break;
            }

            int move = arr[cnt_index];

            // 첫번째 말 움직이기
            if (!isOut(cnt.first, move)) {
                int route = cnt.first.first;
                int next = cnt.first.second + move;
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({{route, next}, cnt.second, cnt.third, cnt.forth, next_total});
                }
            }

            // 두번째 말 움직이기
            if (!isOut(cnt.second, move)) {
                int route = cnt.second.first;
                int next = cnt.second.second + move;
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                } else {
                    q.push({cnt.first, {route, next}, cnt.third, cnt.forth, next_total});
                }
            }

            // 세번째 말 움직이기
            if (!isOut(cnt.third, move)) {
                int route = cnt.third.first;
                int next = cnt.third.second + move;
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
                    q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
                } else {
                    q.push({cnt.first, cnt.second, {route, next}, cnt.forth, next_total});
                }
            }

            // 네번째 말 움직이기
            if (!isOut(cnt.forth, move)) {
                int route = cnt.forth.first;
                int next = cnt.forth.second + move;
                int next_total = cnt.total + score[route][next];

                if (route == 0) {
                    route = switchIndex(next);
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