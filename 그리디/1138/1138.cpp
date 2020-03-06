#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int num;
int arr[11];
int result[11];

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int cntIndex = i;
        int zeroNum = arr[i];

        for (int j = 0; j < N; j++) {
            if (zeroNum == 0 && result[j] == 0) {
                result[j] = cntIndex + 1;
                break;
            }
            if (result[j] == 0) {
                zeroNum--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
