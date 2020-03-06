#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];
int n, m, day;
class tomato
{
public:
    int row, col, date;

    tomato(int i, int j, int d)
    {
        row = i;
        col = j;
        date = d;
    }
};

queue<tomato> q;

int main(void)
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                tomato tmp(i,j,0);
                q.push(tmp);
            }
        }
    }

    while (!q.empty())
    {
        tomato cnt = q.front();
        q.pop();
        int row = cnt.row;
        int col = cnt.col;
        int date = cnt.date;

        // 오른쪽
        if (row + 1 < n)
        {
            int con = box[row+1][col];
            if (con == 0)
            {
                box[row+1][col] = 1;
                tomato next(row+1, col, date+1);
                q.push(next);
            }
        }
        // 왼쪽
        if (row - 1 >= 0)
        {
            int con = box[row-1][col];
            if (con == 0)
            {
                box[row-1][col] = 1;
                tomato next(row-1, col, date+1);
                q.push(next);
            }
        }
        // 위
        if (col - 1 >= 0)
        {
            int con = box[row][col-1];
            if(con == 0)
            {
                box[row][col-1] = 1;
                tomato next(row, col-1, date+1);
                q.push(next);
            }
        }
        // 아래
        if (col + 1 < m)
        {
            int con = box[row][col+1];
            if(con == 0)
            {
                box[row][col+1] = 1;
                tomato next(row, col+1, date+1);
                q.push(next);
            }
        }
        

        if(date>day)
            day = date;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(box[i][j] == 0)
            {
                cout<<-1<<'\n';
                return 0;
            }
        }
    }
    cout<<day<<'\n';
    return 0;
}