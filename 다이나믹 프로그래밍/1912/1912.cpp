#include <iostream>
#include <vector>
using namespace std;

int maxValue;
int n;

vector<int> arr;
vector<int> sumArr;

int main(void)
{
    cin >> n;
    arr = vector<int>(n);
    sumArr = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxValue = arr[0];
    sumArr[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] + sumArr[i - 1] > arr[i]) {
            sumArr[i] = sumArr[i - 1] + arr[i];

        } else {
            sumArr[i] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << sumArr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < sumArr.size(); i++) {
        if (maxValue < sumArr[i]) {
            maxValue = sumArr[i];
        }
    }

    cout << maxValue << '\n';
    return 0;
}