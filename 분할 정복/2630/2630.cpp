#include <iostream>
using namespace std;

#define WHITE 0
#define BLUE 1

int N;
int arr[128][128];
int white_num;
int blue_num;

void divide(int n, int y_start, int x_start)
{
    bool will_divide = false;
    int color = arr[y_start][x_start];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (color != arr[y_start + i][x_start + j])
            {
                will_divide = true;
                break;
            }
        }

    if (will_divide == true)
    {
        int size = n / 2;
        divide(size, y_start, x_start);
        divide(size, y_start, x_start + size);
        divide(size, y_start + size, x_start);
        divide(size, y_start + size, x_start + size);
    }

    else
    {
        if (color == WHITE)
        {
            white_num++;
            return;
        }
        else
        {
            blue_num++;
            return;
        }
    }
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    divide(N, 0, 0);
    cout << white_num << '\n';
    cout << blue_num << '\n';

    return 0;
}