#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define MAX 10000001

int a, b;
bool check[MAX];
vector<int> v;

int main(void) {
    cin >> a >> b;

    for (int i = 2; i * i <= MAX; i++) {
        for (int j = 2; i * j <= MAX; j++) {
            check[i * j] = true;
        }
    }
    if (b >= MAX) {
        b = MAX;
    }

    for (int i = a; i <= b; i++) {
        if (check[i] == false) {
            if (i < 10) {
                v.push_back(i);
            } else if (i < 100) {
                int r = i % 10;
                int qu = i / 10;

                if (r == qu) {
                    v.push_back(i);
                }
            } else if (i < 1000) {
                int r10 = i % 10;
                int q100 = i / 100;

                if (r10 == q100) {
                    v.push_back(i);
                }
            } else if (i < 10000) {
                int r10 = i % 10;
                int r100 = (i % 100) / 10;
                int q100 = i / 100;

                if (r10 * 10 + r100 == q100) {
                    v.push_back(i);
                }
            } else if (i < 100000) {
                int r10 = i % 10;
                int r100 = (i % 100) / 10;
                int q1000 = i / 1000;

                if (r10 * 10 + r100 == q1000) {
                    v.push_back(i);
                }
            } else if (i < 1000000) {
                int r10 = i % 10;
                int r100 = (i % 100) / 10;
                int r1000 = (i % 1000) / 100;
                int q1000 = i / 1000;

                if (r10 * 100 + r100 * 10 + r1000 == q1000) {
                    v.push_back(i);
                }
            } else if (i < 10000000) {
                int r10 = i % 10;
                int r100 = (i % 100) / 10;
                int r1000 = (i % 1000) / 100;
                int q10000 = i / 10000;

                if (r10 * 100 + r100 * 10 + r1000 == q10000) {
                    v.push_back(i);
                }
            } else if (i < 100000000) {
                int r10 = i % 10;
                int r100 = (i % 100) / 10;
                int r1000 = (i % 1000) / 100;
                int r10000 = (i % 10000) / 1000;
                int q10000 = i / 10000;

                if (r10 * 1000 + r100 * 100 + r1000 * 10 + r10000 == q10000) {
                    v.push_back(i);
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    cout << -1 << '\n';

    return 0;
}