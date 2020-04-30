#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v;
vector<int> result;
int N, K;

int initial_size;

void makeYosepuse(int num) {
    result.push_back(v[num]);
    v[num] = 0;

    if (result.size() == N) {
        return;
    }

    vector<int> temp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            temp.push_back(v[i]);
        }
    }
    v = temp;
    int nextIndex = (num + K - 1) % v.size();

    makeYosepuse(nextIndex);
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        v.push_back(i + 1);
    }

    initial_size = v.size();

    makeYosepuse(K - 1);

    cout << '<' << result[0];
    for (int i = 1; i < result.size(); i++) {
        cout << ", " << result[i];
    }
    cout << '>';

    return 0;
}