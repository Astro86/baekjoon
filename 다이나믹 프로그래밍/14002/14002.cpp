#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;

int main(void)
{
    cin >> n;
    vector<int> v(n);
    vector<int> num(n);
    vector<int> trace(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int cntlimit = v[i];
        int maxNum = 0;
        int preindex = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] < cntlimit && maxNum < num[j]) {
                maxNum = num[j];
                preindex = j;
            }
        }

        num[i] = maxNum + 1;
        trace[i] = preindex;
    }

    int maxValue = 0;
    int index;
    for (int i = 0; i < n; i++) {
        if (maxValue < num[i]) {
            maxValue = num[i];
            index = i;
        }
    }

    stack<int> st;
    for (int i = 0; i < maxValue; i++) {
        st.push(index);
        index = trace[index];
    }

    cout << maxValue << '\n';
    for (int i = 0; i < maxValue; i++) {
        cout << v[st.top()] << " ";
        st.pop();
    }
    return 0;
}