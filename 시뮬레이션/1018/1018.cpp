#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m;
vector<vector<char>> map;
vector<vector<int>> vec;

int main(void)
{
    cin >> n >> m;

    map = vector<vector<char>>(n, vector<char>(m, 0));
    vec = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if ((i + j) % 2 == 0 && map[i][j] != 'W')
                vec[i][j]++;
            if ((i + j) % 2 == 1 && map[i][j] != 'B')
                vec[i][j]++;
        }
    }

    int ans = n * m;
    for (int i = 0; i + 7 < n; i++)
    {
        for (int j = 0; j + 7 < m; j++)
        {
            int cnt = 0;
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    cnt += vec[i + y][j + x];
                }
            }

            cnt = min(cnt, 64 - cnt);
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}
