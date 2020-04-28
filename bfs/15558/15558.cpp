#include <bits/stdc++.h>
using namespace std;

/*
지도는 총 2개의 줄로 나누어져 있으며, 각 줄은 N개의 칸으로 나누어져 있다. 
칸은 위험한 칸과 안전한 칸으로 나누어져 있고, 안전한 칸은 유저가 이동할 수 있는 칸, 위험한 칸은 이동할 수 없는 칸이다.

가장 처음에 유저는 왼쪽 줄의 1번 칸 위에 서 있으며, 매 초마다 아래 세 가지 행동중 하나를 해야 한다.
    한 칸 앞으로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i+1번 칸으로 이동한다.
    한 칸 뒤로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i-1번 칸으로 이동한다.
    반대편 줄로 점프한다. 이때, 원래 있던 칸보다 k칸 앞의 칸으로 이동해야 한다. 
    예를 들어, 현재 있는 칸이 왼쪽 줄의 i번 칸이면, 오른쪽 줄의 i+k번 칸으로 이동해야 한다.

N번 칸보다 더 큰 칸으로 이동하는 경우에는 게임을 클리어한 것이다.

게임을 재밌게 하기 위해서, 상근이는 1초에 한 칸씩 각 줄의 첫 칸이 사라지는 기능을 만들었다. 
즉, 게임을 시작한지 1초가 지나면 1번 칸이 사라지고, 2초가 지나면 2번 칸이 사라진다. 편의상 유저가 먼저 움직이고, 칸이 사라진다고 가정한다. 
즉, 이번에 없어질 칸이 3번 칸인데, 상근이가 3번 칸에 있다면, 3번 칸에서 다른 칸으로 이동하고 나서 3번 칸이 없어지는 것이다.
*/

/*
첫째 줄에 N과 k가 주어진다. (1 ≤ N, k ≤ 100,000)
둘째 줄에는 왼쪽 줄의 정보가 주어진다. 
i번째 문자가 0인 경우에는 위험한 칸이고, 1인 경우에는 안전한 칸이다. 
셋째 줄에는 오른쪽 줄의 정보가 주어지고, 각 문자의 의미는 왼쪽 줄의 의미와 동일하다.
왼쪽 줄의 1번 칸은 항상 안전한 칸이다.
*/

int N, K;
// 0은 왼쪽, 1은 오른쪽;
int Map[2][200020];
bool visited[2][200020];

struct point {
    int cnt;
    // 0 = 왼쪽, 1 = 오른쪽
    int state;
};

int main(void) {
    scanf("%d %d", &N, &K);

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= N; i++) {
            scanf("%1d", &Map[k][i]);
        }
    }

    queue<point> q;
    q.push({1, 0});
    visited[1][0] = true;
    int remove_point = 1;

    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            int index = q.front().cnt;
            bool state = q.front().state;
            q.pop();

            if (index > N) {
                printf("1\n");
                return 0;
            }

            if (Map[state][index] == -1) {
                continue;
            }

            // 앞으로 움직인다.
            int move_front = index + 1;
            if (move_front > N || (Map[state][move_front] == 1 && visited[state][move_front] == false)) {
                visited[state][move_front] = true;
                q.push({move_front, state});
            }

            // 뒤로 움직인다.
            int move_back = index - 1;
            if (move_back > N || (Map[state][move_back] == 1 && visited[state][move_back] == false)) {
                visited[state][move_back] = true;
                q.push({move_back, state});
            }

            // 다른쪽 지도로 움직인다.
            int move_other = index + K;
            if (move_other > N || (Map[1 ^ state][move_other] == 1 && visited[1 ^ state][move_other] == false)) {
                visited[1 ^ state][move_other] = true;
                q.push({move_other, 1 ^ state});
            }
        }

        for (int i = 0; i < 2; i++) {
            Map[i][remove_point] = -1;
        }
        remove_point++;
    }
    printf("%d\n", 0);
    return 0;
}