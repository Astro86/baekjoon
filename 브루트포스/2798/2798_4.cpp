#include <math.h>

#include <algorithm>
#include <iostream>
using namespace std;

// 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다.
// 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는다.

// 합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.
// 첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.

int N, M;
int card[101];

int result;

void choiceCard(int start, int sum, int level) {
    if (sum > M) {
        return;
    }

    if (level == 3) {
        if (sum > result) {
            result = sum;
        }
        return;
    }

    for (int i = start; i < N; i++) {
        choiceCard(i + 1, sum + card[i], level + 1);
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

    choiceCard(0, 0, 0);

    cout << result << '\n';

    return 0;
}