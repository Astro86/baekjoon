#include <iostream>
#include <vector>
using namespace std;

#define MAX 1100000
int n;
bool check[MAX];
vector<int> v;

int main(void)
{
    cin >> n;

    for (int i = 2; i * i < MAX; i++) {
        for (int j = 2; i * j < MAX; j++) {
            check[i * j] = true;
        }
    }

    for (int i = 2; i < MAX; i++) {
        if (check[i] == false) {
            if (i < 10) {
                v.push_back(i);
            } else if (i < 100) {
                int reminder = i % 10;
                int quotient = i / 10;

                if (reminder == quotient) {
                    v.push_back(i);
                }
            } else if (i < 1000) {
                int reminder10 = i % 10;
                int quotient100 = i / 100;

                if (reminder10 == quotient100) {
                    v.push_back(i);
                }
            } else if (i < 10000) {
                int reminder10 = i % 10;
                int reminder100 = (i % 100) / 10;
                int quotient100 = i / 100;

                if (reminder10 * 10 + reminder100 == quotient100) {
                    v.push_back(i);
                }
            } else if (i < 100000) {
                int reminder10 = i % 10;
                int reminder100 = (i % 100) / 10;
                int quotient1000 = i / 1000;

                if (reminder10 * 10 + reminder100 == quotient1000) {
                    v.push_back(i);
                }
            } else if (i < 1000000) {
                int reminder10 = i % 10;
                int reminder100 = (i % 100) / 10;
                int reminder1000 = (i % 1000) / 100;
                int quotient1000 = i / 1000;

                if (reminder10 * 100 + reminder100 * 10 + reminder1000 == quotient1000) {
                    v.push_back(i);
                }
            } else {
                int reminder10 = i % 10;
                int reminder100 = (i % 100) / 10;
                int reminder1000 = (i % 1000) / 10;
                int quotient10000 = i / 10000;

                if (reminder10 * 100 + reminder100 * 10 + reminder1000 == quotient10000) {
                    v.push_back(i);
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        // cout << v[i] << endl;
        if (v[i] >= n) {
            cout << v[i] << '\n';
            break;
        }
    }

    return 0;
}