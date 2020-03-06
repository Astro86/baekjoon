#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
pair<int, int> arr[100001];

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = { temp, i + 1 };
    }
    sort(arr, arr + n);

    while (m--) {
        int start, end, number;
        cin >> start >> end >> number;

        int num = 0;
        for (int i = 0; i < n; i++) {
            int cntValue = arr[i].first;
            int cntIndex = arr[i].second;

            if (start <= cntIndex && cntIndex <= end) {
                num++;
            }
            if (num == number) {
                cout << cntValue << '\n';
                break;
            }
        }
    }
    return 0;
}