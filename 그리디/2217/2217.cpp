#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    cin >> N;
    vector<int> weight(N);
    vector<int> totalWeight(N);

    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end(), cmp);

    int maxWeight = 0;
    for (int i = 0; i < N; i++) {
        if (maxWeight < (i + 1) * weight[i]) {
            maxWeight = (i + 1) * weight[i];
        }
    }

    cout << maxWeight << '\n';
    return 0;
}