#include <iostream>
using namespace std;

int n;
// 해당 열에 놓여져 있는지 확인
bool col[16];
bool chess[16][16];
int total;

void nqeen(int row)
{
    if (row == n)
    {
        total++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // 열에 대한 유효성 검사
        if (col[i] != false)
        {
            continue;
        }

        bool fp = true;
        // 대각선에 대한 유효성 검사가 들어가야 한다.
        for (int j = 1; j <= row; j++)
        {
            // 왼쪽 대각선에 대한 확인
            if (i - j >= 0)
            {
                if (chess[row - j][i - j] != false)
                {
                    fp = false;
                }
            }
            // 오른쪽 대각선에 대한 확인
            if (i + j < n)
            {
                if (chess[row - j][i + j] != false)
                {
                    fp = false;
                }
            }
        }

        // 유효성 검사 확인 후
        if (fp)
        {
            chess[row][i] = true;
            col[i] = true;
            nqeen(row + 1);
            col[i] = false;
            chess[row][i] = false;
        }
    }
}

int main(void)
{
    cin >> n;
    nqeen(0);
    cout << total << endl;
    return 0;
}