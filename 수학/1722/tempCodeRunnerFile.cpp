#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
int flag;

int main(void) {
    cin >> n;
    vector<bool> number(n + 1, false);
    vector<int> weights(n + 1);
    vector<int> v(n);
    long long num;

    stack<long long> st;
    st.push(1);
    for (int i = 2; i < n; i++) {
        st.push(st.top() * i);
    }

    cin >> flag;

    if (flag == 1) {
        cin >> num;
        // 7 6 5 2 3 4 1
        num--;
        while (!st.empty()) {
            long long cntValue = st.top();
            st.pop();

            int index = 1;
            for (int i = 1; i <= n; i++) {
                if (number[i] == false) {
                    index = i;
                    break;
                }
            }

            while (num >= cntValue) {
                while (number[++index] == true) {
                }
                num -= cntValue;
            }

            number[index] = true;
            cout << index << ' ';
        }

        for (int i = 1; i <= n; i++) {
            if (number[i] == false) {
                cout << i << ' ';
                return 0;
            }
        }
    }

    if (flag == 2) {
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int index = 0;
        long long total = 1;
        while (!st.empty()) {
            long long cntValue = st.top();
            st.pop();

            int numberIndex = 1;
            int countNum = 0;
            while (v[index] != numberIndex) {
                if (number[numberIndex] == false) {
                    countNum++;
                }
                numberIndex++;
            }

            number[numberIndex] = true;
            index++;
            total += countNum * cntValue;
        }
        cout << total << endl;
    }

    return 0;
}