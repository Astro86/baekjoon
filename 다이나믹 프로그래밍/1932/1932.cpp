#include <iostream>
using namespace std;

int tri[550][550];
int memo[550][550];
int n;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    memo[0][0] = tri[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (memo[i][j] != 0) {
                memo[i][j] = max(memo[i][j], tri[i][j] + memo[i - 1][j]);
            } else {
                memo[i][j] = tri[i][j] + memo[i - 1][j];
            }

            if (memo[i][j + 1] != 0) {
                memo[i][j + 1] = max(memo[i][j + 1], tri[i][j + 1] + memo[i - 1][j]);
            } else {
                memo[i][j + 1] = tri[i][j + 1] + memo[i - 1][j];
            }
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        result = max(result, memo[n - 1][i]);
    }

    cout << result << '\n';
    return 0;
}