#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int k;

int main(void)
{
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        int temp;
        scanf("%d", &temp);

        if (temp == 0)
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(temp);
        }
    }

    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    printf("%d\n", sum);
    return 0;
}