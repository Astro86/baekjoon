#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T;
stack<char> st;
string s;

int main(void)
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        int string_stack = 0;
        int s_size = s.length();
        bool for_break = false;

        for (int i = 0; i < s_size; i++)
        {
            if (s[i] == '(')
            {
                string_stack++;
            }
            else
            {
                if (string_stack == 0)
                {
                    cout << "NO" << '\n';
                    for_break = true;
                    break;
                }
                string_stack--;
            }
        }

        if (!for_break)
        {
            if (string_stack == 0)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}