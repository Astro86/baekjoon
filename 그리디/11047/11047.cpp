#include <iostream>
#include <vector>
using namespace std;

int n;
int k;

int main(void)
{
    scanf("%d %d", &n, &k);

    vector<int> coin(n, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }

    int coin_num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= coin[i])
        {
            coin_num += (k / coin[i]);
            k %= coin[i];
        }
    }
    cout << coin_num << '\n';
    return 0;
}