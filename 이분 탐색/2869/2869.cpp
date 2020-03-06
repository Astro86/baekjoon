#include <iostream>
using namespace std;

int A, B, V;
int cntLength = 0;
int day;

int main(void)
{
    cin >> A >> B >> V;
    int dayNight = V - A;
    day = dayNight / (A - B) + 1;

    if (dayNight % (A - B) == 0) {
        cout << day << '\n';
    } else {
        cout << day + 1 << '\n';
    }

    return 0;
}