#include <iostream>
using namespace std;

int k;
char arr[10];
int maxNum[11];
int minNum[11];
bool check[10];

void findMaxValue()
{
    int n = 0;
    int cntNum = 9;

    for (int i = 0; i < k; i++) {
        if (arr[i] == '<') {
            while (arr[i] == '<') {
                n++;
                i++;
            }
            for (int j = 0; j <= n; j++) {
                maxNum[i - j] = cntNum--;
            }
            n = 0;
        } else {
            maxNum[i] = cntNum--;
        }
    }

    if (arr[k - 1] == '>')
        maxNum[k] = cntNum;

    for (int i = 0; i <= k; i++) {
        cout << maxNum[i];
    }
    cout << endl;
}

void findMinValue()
{
    int n = 0;
    int cntNum = 0;

    for (int i = 0; i < k; i++) {
        if (arr[i] == '<') {
            minNum[i] = cntNum++;
        } else {
            while (arr[i] == '>') {
                i++;
                n++;
            }

            for (int j = 0; j <= n; j++) {
                minNum[i - j] = cntNum++;
            }
            n = 0;
        }
    }

    if (arr[k - 1] == '<')
        minNum[k] = cntNum;

    for (int i = 0; i <= k; i++) {
        cout << minNum[i];
    }
    cout << endl;
}

int main(void)
{
    cin >> k;

    for (int i = 0; i <= k; i++) {
        maxNum[i] = -1;
        minNum[i] = -1;
    }

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    findMaxValue();
    findMinValue();
    return 0;
}