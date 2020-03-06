#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int m;
vector<int> v;
string s;
string cmpString = "";

int findIOI()
{
    int length = s.length();
    // int cmpLength = cmpString.length();
    int totalNum = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == 'I') {
            int num = 0;
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                num++;
                i += 2;
            }
            if (num - (n - 1) > 0) {
                v.push_back(num - (n - 1));
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        totalNum += v[i];
        // cout << v[i] << endl;
    }

    return totalNum;
}

int main(void)
{
    cin >> n >> m >> s;
    cmpString += "I";
    for (int i = 0; i < n; i++) {
        cmpString += "O";
        cmpString += "I";
    }
    cout << findIOI() << '\n';
}