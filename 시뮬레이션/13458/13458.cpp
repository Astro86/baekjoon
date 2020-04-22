#include <bits/stdc++.h>
using namespace std;

#define MAX_ROOM 1000000

int room[MAX_ROOM];
long long supervisor;
int N, B, C;

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> room[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        int cnt_student = room[i];

        supervisor++;
        cnt_student -= B;
        if (cnt_student > 0) {
            if (cnt_student % C == 0) {
                supervisor += cnt_student / C;
            } else {
                supervisor += cnt_student / C + 1;
            }
        }
    }

    cout << supervisor << '\n';
    return 0;
}