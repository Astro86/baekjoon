#include <bits/stdc++.h>
using namespace std;

set<string> s;
int Map[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void nCr(int y, int x, int num, string numbers) {
    if (num == 6) {
        s.insert(numbers);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
            nCr(ny, nx, num + 1, numbers + to_string(Map[ny][nx]));
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string numbers;
            numbers += to_string(Map[i][j]);
            nCr(i, j, 1, numbers);
        }
    }

    cout << s.size() << '\n';
    return 0;
}