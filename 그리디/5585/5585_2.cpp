#include <iostream>
using namespace std;

int value, num;
int coin[] = {500, 100, 50, 10, 5, 1};

int main(void)
{
    cin >> value;

    int changes = 1000 - value;

    for (int i = 0; i < 6; i++)
    {
        num += changes / coin[i];
        changes = changes % coin[i];
    }

    cout << num << '\n';
    return 0;
}