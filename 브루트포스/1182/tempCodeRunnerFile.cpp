#include <iostream>
using namespace std;

int N, S;
int arr[21];
int num;

void calculate(int index, int n, int sum)
{
    if (n != 0 && sum == S) {
        num++;
        return;
    }

    for (int i = index; i < N; i++) {
        calculate(i + 1, n + 1, sum + arr[i]);
    }
}

int main(void)
{
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    calculate(0, 0, 0);

    cout << num << '\n';
}