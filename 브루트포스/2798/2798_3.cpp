#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int sum_limit;
int max_sum;
vector<int> card;
struct card_sum {
    int start_index;
    int sum;
    int level;
    card_sum(int i, int j, int k) : start_index(i), sum(j), level(k) {}
};
queue<card_sum> q;

void blackJack() {
    while (!q.empty()) {
        int start_index = q.front().start_index;
        int sum = q.front().sum;
        int level = q.front().level;
        q.pop();

        if (start_index > n || sum > sum_limit)
            continue;

        if (level == 3) {
            if (max_sum < sum) {
                max_sum = sum;
                continue;
            }
            continue;
        } else if (level > 3)
            break;

        for (int i = start_index; i < n; i++) {
            card_sum temp(i + 1, sum + card[i], level + 1);
            q.push(temp);
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &sum_limit);
    card = vector<int>(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    card_sum temp(0, 0, 0);
    q.push(temp);
    blackJack();

    printf("%d\n", max_sum);
    return 0;
}