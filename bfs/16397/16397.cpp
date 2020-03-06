#include <iostream>
#include <queue>
using namespace std;

// n : led에 표시된 수
// t : 버튼을 누를 수 있는 최대 횟수
// g : 탈출을 위해 똑같이 만들어야 하는 수
int n, t, g;
queue<pair<int, int>> q;
bool check[99999];

int maxMinus(int x)
{
    if (x < 10)
    {
        return x - 1;
    }
    else if (x < 100)
    {
        return x - 10;
    }
    else if (x < 1000)
    {
        return x - 100;
    }
    else if (x < 10000)
    {
        return x - 1000;
    }
    else
    {
        return x - 10000;
    }
}

int main(void)
{
    cin >> n >> t >> g;
    q.push({n, 0});
    check[n] = true;

    if (n == g)
    {
        cout << 0 << '\n';
        return 0;
    }

    while (!q.empty())
    {
        int cnt_value = q.front().first;
        int cnt_num = q.front().second;
        q.pop();

        if (cnt_num == t)
        {
            break;
        }

        int buttonA = cnt_value + 1;
        if (0 <= buttonA && buttonA <= 99999 && !check[buttonA])
        {
            if (buttonA == g)
            {
                cout << cnt_num + 1 << '\n';
                return 0;
            }

            check[buttonA] = true;
            q.push({buttonA, cnt_num + 1});
        }
        int buttonB = cnt_value * 2;
        if (buttonB <= 99999)
        {
            int buttonB_maxMinux = maxMinus(buttonB);
            if (0 <= buttonB_maxMinux && !check[buttonB_maxMinux])
            {
                if (buttonB_maxMinux == g)
                {
                    cout << cnt_num + 1 << '\n';
                    return 0;
                }

                check[buttonB_maxMinux] = true;
                q.push({buttonB_maxMinux, cnt_num + 1});
            }
        }
    }
    cout << "ANG" << '\n';
    return 0;
}