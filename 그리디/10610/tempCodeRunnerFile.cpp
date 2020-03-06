#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char arr[100001];
string N;
bool isZero = false;
bool isPossible = false;

bool cmp(char a, char b)
{
    return a > b;
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '0') {
            isZero = true;
            break;
        }
    }

    int totalNum = 0;
    for (int i = 0; i < N.length(); i++) {
        arr[i] = N[i];
        totalNum += N[i] - '0';
    }

    if (totalNum % 3 == 0) {
        isPossible = true;
    }

    if (isZero && isPossible) {
        sort(arr, arr + N.length(), cmp);
        for (int i = 0; i < N.length(); i++) {
            cout << arr[i];
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}