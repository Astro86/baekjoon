#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
int t;

int main(void)
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        int s_size = s.length();
        stack<char> st;
        bool for_break = false;

        for (int i = 0; i < s_size; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    for_break = true;
                    cout << "NO" << '\n';
                    break;
                }
                st.pop();
            }
        }

        if(!for_break)
        {
            if(st.empty())
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
    }

    return 0;
}