#include <iostream>
#include <vector>
using namespace std;

int n;
int sum_limit;
int max_sum;
vector<int> card;

void blackJack(int start_index, int sum, int depth) {
    if (sum > sum_limit)
        return;

    if (depth == 3) {
        cout << sum << endl;
        if (max_sum < sum) {
            max_sum = sum;
            return;
        }
        return;
    }

    for (int i = start_index; i < n; i++) {
        blackJack(i + 1, sum + card[i], depth + 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &sum_limit);
    card = vector<int>(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    blackJack(0, 0, 0);

    printf("%d\n", max_sum);
    return 0;
}