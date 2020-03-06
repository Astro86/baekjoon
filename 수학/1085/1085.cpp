#include <iostream>
using namespace std;

int x, y, w, h;
int minLength = 1000000000;

int main(void)
{
    cin >> x >> y >> w >> h;
    minLength = min(minLength, x);
    minLength = min(minLength, y);
    minLength = min(minLength, abs(w - x));
    minLength = min(minLength, abs(h - y));

    cout << minLength << '\n';
    return 0;
}