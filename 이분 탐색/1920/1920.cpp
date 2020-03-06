#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int findNum[100001];

void Binary_Search(int num)
{
    int start, end, mid;
    start = 0;
    end = n - 1;

    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == num) {
            break;
        } else if (arr[mid] > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (arr[mid] == num) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        // cout << temp << " ";
        Binary_Search(temp);
    }
}