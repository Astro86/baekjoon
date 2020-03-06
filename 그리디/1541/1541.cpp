#include <iostream>
#include <queue>
#include <string>
using namespace std;

string exp;
queue<int> value;
queue<char> sign;

int main(void)
{
    cin >> exp;

    int expLength = exp.length();

    int temp = 0;
    for (int i = 0; i < expLength; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            temp = temp * 10 + (exp[i] - '0');
        } else {
            value.push(temp);
            temp = 0;
            sign.push(exp[i]);
        }
    }
    value.push(temp);

    queue<int> q;
    q.push(value.front());
    value.pop();

    while (!sign.empty()) {
        char tempSign = sign.front();
        sign.pop();

        if (tempSign == '-') {
            int stack = value.front();
            value.pop();

            while (sign.front() == '+' && !sign.empty()) {
                sign.pop();
                stack += value.front();

                value.pop();
            }
            q.push(stack * (-1));
        } else {
            q.push(value.front());
            value.pop();
        }
    }

    int result = 0;
    while (!q.empty()) {
        result += q.front();
        q.pop();
    }

    cout << result << '\n';
    return 0;
}