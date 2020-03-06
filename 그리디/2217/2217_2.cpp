#include <iostream>
using namespace std;

int n;
int minValue = 10000;
int maxValue;

int main(void)
{
    cin >> n;

    int num = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp >= minValue) {
            num++;
        } else {
            if (minValue * num <= temp * (num + 1)) {
                minValue = temp;
                num++;
            }
        }
    }

    cout << minValue * num << '\n';
}