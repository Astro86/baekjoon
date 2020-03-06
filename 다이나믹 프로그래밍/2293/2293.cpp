#include <algorithm>
#include <iostream>
using namespace std;

int n, k;
int arr[110];
int score[100001];

int main(void)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    score[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int move = arr[i];
            int pre = j - move;

            if (pre >= 0) {
                score[j] = score[j] + score[pre];
            }
        }
    }

    cout << score[k] << '\n';
    return 0;
}