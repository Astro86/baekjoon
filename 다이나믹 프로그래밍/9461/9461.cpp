#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;
        vector<long long> v;

        v.push_back(1);
        v.push_back(1);
        v.push_back(1);

        for (int i = 0; i < N; i++) {
            long long temp;
            temp = v[i] + v[i + 1];
            v.push_back(temp);

            if (v.size() == N) {
                break;
            }
        }

        cout << v[N - 1] << '\n';
    }

    return 0;
}