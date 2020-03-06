#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int main(void)
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int totalSum = 0;
    for (int i = 1; i <= v.size(); i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += v[j];
        }
        totalSum += sum;
    }

    cout << totalSum << '\n';
    return 0;
}
