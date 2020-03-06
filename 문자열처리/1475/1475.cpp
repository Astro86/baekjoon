#include <iostream>
#include <string>
using namespace std;

string N;
int arr[10];

int main(void)
{
    cin >> N;

    int string_size = N.size();
    for (int i = 0; i < string_size; i++) {
        char cntNum = N[i];
        arr[cntNum - '0']++;
    }

    int NineSix = arr[6] + arr[9];
    if (NineSix % 2 == 1) {
        arr[6] = NineSix / 2 + 1;
        arr[9] = NineSix / 2 + 1;
    } else {
        arr[6] = NineSix / 2;
        arr[9] = NineSix / 2;
    }

    int maxNum = 0;
    for (int i = 0; i < 10; i++) {
        if (maxNum < arr[i]) {
            maxNum = arr[i];
        }
    }

    cout << maxNum << '\n';
}