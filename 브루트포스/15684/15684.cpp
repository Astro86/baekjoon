#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, H;
// vector<vector<pair<int, int>>> ladder;
int ladder[33][11];
bool possible;
int totalNum = 100000000;

bool isI(int start, int cnt, int layer)
{
    int cntValue = cnt;
    for (int i = layer; i <= H + 1; i++) {
        if (i == H + 1 && start == cntValue) {
            return true;
        }

        int nextL = cntValue - 1;
        int nextR = cntValue + 1;

        if (nextL >= 1 && ladder[i][nextL] == 1) {
            cntValue = nextL;
        } else if (nextR <= N && ladder[i][cntValue] == 1) {
            cntValue = nextR;
        } else {
            continue;
        }
    }

    return false;
}

void makeLadder(int index, int num)
{
    if (num >= 4) {
        return;
    }

    bool isPossible = false;
    for (int i = 1; i <= N; i++) {
        isPossible = isI(i, i, 1);

        if (!isPossible) {
            isPossible = false;
            break;
        }
    }
    if (isPossible) {
        if (totalNum > num) {
            totalNum = num;
        }
        possible = true;
    }

    for (int i = index; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ladder[i][j] == 0) {
                if (j - 1 >= 1 && ladder[i][j - 1] == 1) {
                    continue;
                }
                if (j + 1 < N && ladder[i][j + 1] == 1) {
                    continue;
                }
                ladder[i][j] = 1;
                makeLadder(i, num + 1);
                ladder[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;
        ladder[a][b] = 1;
    }

    makeLadder(1, 0);

    if (possible == false) {
        cout << -1 << '\n';
    } else
        cout << totalNum << '\n';
    return 0;
}