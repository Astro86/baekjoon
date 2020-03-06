#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[22][22];
int s[22][22];
bool check[22];
int minValue = 100000000;

void choice(int index, int n)
{
    if (n == N / 2) {
        vector<int> v1;
        for (int i = 1; i <= N; i++) {
            if (check[i] == true) {
                v1.push_back(i);
            }
        }

        int sum1 = 0;
        for (int i = 0; i < v1.size(); i++) {
            int cntI = v1[i];

            for (int j = 0; j < v1.size(); j++) {
                int cntJ = v1[j];

                if (i == j) {
                    continue;
                }
                sum1 += arr[cntI][cntJ];
            }
        }

        vector<int> v2;
        for (int i = 1; i <= N; i++) {
            if (check[i] == false) {
                v2.push_back(i);
            }
        }

        int sum2 = 0;
        for (int i = 0; i < v2.size(); i++) {
            int cntI = v2[i];

            for (int j = 0; j < v2.size(); j++) {
                int cntJ = v2[j];

                if (i == j) {
                    continue;
                }

                sum2 += arr[cntI][cntJ];
            }
        }

        if (minValue > abs(sum1 - sum2)) {
            minValue = abs(sum1 - sum2);
        }
    }

    for (int i = index; i <= N; i++) {
        check[i] = true;
        choice(i + 1, n + 1);
        check[i] = false;
    }
}

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    choice(1, 0);
    cout << minValue << endl;
}