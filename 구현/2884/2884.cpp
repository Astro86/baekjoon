#include <iostream>
using namespace std;

int h, m;

int main(void)
{
    cin >> h >> m;

    if (h == 0 && m < 45) {
        h = 23;
        m += 60 - 45;
    } else if (h == 0 && m >= 45) {
        m -= 45;
    } else if (m < 45) {
        h -= 1;
        m += 60 - 45;
    } else {
        m -= 45;
    }

    cout << h << " " << m << '\n';
    return 0;
}