#include <iostream>
using namespace std;

int value, num;

int main(void)
{
    cin >> value;

    int changes = 1000 - value;

    num += changes / 500;
    changes = changes % 500;

    num += changes / 100;
    changes = changes % 100;

    num += changes / 50;
    changes = changes % 50;

    num += changes / 10;
    changes = changes % 10;

    num += changes;

    cout << num << '\n';
    return 0;
}