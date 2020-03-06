#include <iostream>
#include <vector>
using namespace std;

vector<long long> v(41);
int num_0[41];
int num_1[41];

int T;

int fibonacci(int n)
{
    if (v[n] != 0)
    {
        return v[n];
    }

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    v[n] = fibonacci(n - 1) + fibonacci(n - 2);
    num_0[n] = num_0[n - 1] + num_0[n - 2];
    num_1[n] = num_1[n - 1] + num_1[n - 2];
    return v[n];
}

int main(void)
{
    cin >> T;

    while (T--)
    {
        for (int i = 0; i <= 40; i++)
        {
            num_0[i] = 0;
            num_1[i] = 0;
            v[i] = 0;
        }
        num_0[0] = 1;
        num_0[1] = 0;
        num_1[0] = 0;
        num_1[1] = 1;

        int n;
        cin >> n;
        fibonacci(n);

        cout << num_0[n] << " " << num_1[n] << '\n';
    }

    return 0;
}