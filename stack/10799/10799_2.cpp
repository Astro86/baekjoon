#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
string s;
int total;

int main(void)
{
    cin >> s;
    int s_size = s.length();

    for (int i = 0; i < s_size; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            
            if (s[i+1] == ')')
            {
                st.pop();
                total += st.size();
                i++;
            }
        }
        else
        {
            total++;
            st.pop();
        }
    }

    cout<<total<<'\n';
    return 0;
}