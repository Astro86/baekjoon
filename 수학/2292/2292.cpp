#include <iostream>
using namespace std;

int a = 1, b;
long long n;

int main(void)
{
    long long c = 0;
    cin >> n;

    int i = 1;
    while (a < n)
    {
        i++;
        b += 6;
        a += b;
        // cout << a << endl;
    }
    cout << i << endl;

    return 0;
}