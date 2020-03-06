#include <iostream>
#include <queue>
using namespace std;

int r, c;
bool alphabet[26];
char board[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct point
{
    int y;
    int x;
    int num;

    point(){};
    point(int a, int b, int c) : y(a), x(b), num(c){};
};
queue<point> q;
int max_count;

int main(void)
{
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &board[i][j]);

    q.push(point(0, 0, 1));

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int num = q.front().num;

        max_count = max(max_count, num);

        int cnt_alphabet = board[y][x] - 'A';
        alphabet[cnt_alphabet] = true;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < r && 0 <= nx && nx <= c)
            {
                int next_alphabet = board[ny][nx];

                if (!alphabet[next_alphabet])
                {
                    q.push(point(ny, nx, num + 1));
                }
            }
        }
    }
}