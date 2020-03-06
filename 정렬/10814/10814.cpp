#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;
// pair<int, string> member[100001];
struct member {
    int index;
    int age;
    string name;
};

member members[100001];

bool cmp(member a, member b)
{
    if (a.age < b.age) {
        return true;
    } else if (a.age == b.age) {
        if (a.index < b.index) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        int age;
        string name;

        cin >> age >> name;
        // member[i] = { age, name };
        members[i] = { i, age, name };
    }

    sort(members, members + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << members[i].age << " " << members[i].name << '\n';
    }

    return 0;
}