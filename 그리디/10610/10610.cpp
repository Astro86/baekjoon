#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s;
int numberArr[100001];
int result;

int main(void)
{
    cin >> s;
    int size = s.length();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        numberArr[i] = s[i] - '0';
        sum += numberArr[i];
    }

    sort(numberArr, numberArr + size, greater<int>());

    if (numberArr[size - 1] == 0 && sum % 3 == 0) {
        for (int i = 0; i < size; i++) {
            cout << numberArr[i];
        }
    } else {
        cout << -1;
    }

    return 0;
}