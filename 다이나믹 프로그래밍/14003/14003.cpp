#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000001

int arr[MAX];
int cache[MAX];
int cacheIndex[MAX];
int trace[MAX];

int n;

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    cacheIndex[1] = 1;
    trace[1] = 0;

    int cacheLength = 1;
    for (int i = 2; i <= n; i++) {
        int cntValue = arr[i];

        if (cache[cacheLength] < cntValue) {

            trace[i] = cacheIndex[cacheLength];

            cacheLength++;
            cache[cacheLength] = cntValue;
            cacheIndex[cacheLength] = i;

        } else {
            int index = lower_bound(cache + 1, cache + cacheLength + 1, cntValue) - cache;
            cache[index] = cntValue;
            cacheIndex[index] = i;

            trace[i] = cacheIndex[index - 1];
        }
    }

    cout << cacheLength << '\n';

    stack<int> st;
    int cnt = cacheIndex[cacheLength];
    for (int i = 0; i < cacheLength; i++) {
        st.push(arr[cnt]);
        cnt = trace[cnt];
    }

    for (int i = 0; i < cacheLength; i++) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}