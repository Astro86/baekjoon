#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> wh_list;
vector<int> score;
int n;

int main(void) {
    scanf("%d", &n);
    wh_list = vector<pair<int, int>>(n, make_pair(0, 0));
    score = vector<int>(n, 1);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wh_list[i].first, &wh_list[i].second);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (wh_list[i].first < wh_list[j].first && wh_list[i].second < wh_list[j].second)
                score[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", score[i]);
    }
    return 0;
}