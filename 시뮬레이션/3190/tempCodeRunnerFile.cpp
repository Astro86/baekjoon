#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[110][110];
bool check[110][110];

queue<pair<int, int>> snake;
queue<pair<int, char>> d;

// 보드의 크기 N, 사과의 개수 K
int N, K;
// 방향 횟수 L
int L;

int count;

// 움직이는 방향
int dir = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void direction(char c)
{
    if (c == 'D')
    {
        dir = (dir + 1) % 4;
    }
    if (c == 'L')
    {
        dir = (dir - 1) % 4;
    }
}

int main(void)
{
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        arr[y][x] = 1;

        // cout << y << " " << x << endl;
    }

    int cnt_x = 1;
    int cnt_y = 1;
    snake.push(make_pair(cnt_y, cnt_x));

    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        int a;
        char c;
        scanf("%d %c", &a, &c);
        d.push(make_pair(a, c));

        // cout << a << " " << c << endl;
    }

    pair<int, char> temp = d.front();
    d.pop();
    int count = temp.first;
    char next_d = temp.second;

    int i = 0;
    while (1)
    {
        if (i == count)
        {
            direction(next_d);
            if (!d.empty())
            {
                pair<int, char> temp = d.front();
                d.pop();
                count = temp.first;
                next_d = temp.second;
            }
        }

        int move_x = cnt_x + dx[dir];
        int move_y = cnt_y + dy[dir];

        // cout << move_y << " " << move_x << endl;

        if (1 <= move_x && move_x <= N && 1 <= move_y && move_y <= N)
        {
            if (arr[move_y][move_x] == 1 && check[move_y][move_x] == false)
            {
                snake.push(make_pair(move_y, move_x));
                check[move_y][move_x] = true;
            }
            else if (arr[move_y][move_x] == 0 && check[move_y][move_x] == false)
            {
                snake.push(make_pair(move_y, move_x));
                check[move_y][move_x] = true;

                pair<int, int> tail = snake.front();
                snake.pop();
                check[tail.first][tail.second] = false;
            }
            else
            {
                break;
            }

            cnt_x = move_x;
            cnt_y = move_y;
        }
        else
        {
            break;
        }
        i++;
    }

    printf("%d\n", i + 1);
    return 0;
}