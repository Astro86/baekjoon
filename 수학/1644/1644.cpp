#include <iostream>
#include <vector>
using namespace std;

int n;
bool check[4000004];
int num[4000004];
vector<int> v;

int main(void)
{
    cin >> n;

    for (int i = 2; i * i <= 4000000; i++) {
        for (int j = 2; j * i <= 4000000; j++) {
            check[i * j] = true;
        }
    }

    for (int i = 2; i <= 4000000; i++) {
        if (check[i] == false) {
            // num[i]++;
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); i++) {

        int sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];

            if (sum > 4000000) {
                break;
            }

            num[sum]++;
        }
    }

    cout << num[n] << '\n';
    return 0;
}