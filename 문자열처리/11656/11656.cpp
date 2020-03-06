#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> v;

int main(void)
{
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        string temp = "";
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
        }
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}