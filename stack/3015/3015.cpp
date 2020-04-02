#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>> st;
long long num;
int bottomValue;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;

    while (N--) {
        int value;
        cin >> value;

        while (!st.empty() && st.top().first < value) {
            pair<int, int> cntValue = st.top();
            st.pop();

            num += cntValue.second;
        }

        if (st.empty()) {
            st.push({value, 1});
        } else {
            if (st.top().first == value) {
                pair<int, int> cntValue = st.top();
                st.pop();

                num += cntValue.second;
                if (!st.empty()) {
                    num++;
                }

                cntValue.second++;
                st.push(cntValue);
            } else {
                num++;
                st.push({value, 1});
            }
        }
    }

    cout << num << '\n';
    return 0;
}