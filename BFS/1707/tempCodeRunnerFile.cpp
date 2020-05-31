#include <iostream>
#include <vector>
using namespace std;

int T, V, E;
vector<vector<int>> arr;
bool colorCheck[20002];
int color[20002];

void paintColor(int cnt)
{
    for (int i = 0; i < arr[cnt].size(); i++) {
        int next = arr[cnt][i];
        if (color[next] == 0) {
            if (color[cnt] == 1) {
                color[next] = 2;
                paintColor(next);
            } else {
                color[next] = 1;
                paintColor(next);
            }
        }
    }
}

bool confirmColor(int cnt)
{
    bool isTrue = true;

    for (int i = 0; i < arr[cnt].size(); i++) {
        int next = arr[cnt][i];

        if (color[cnt] != color[next]) {
            if (colorCheck[next] == false) {
                colorCheck[next] = true;
                isTrue = confirmColor(next);
            }
        } else {
            return false;
        }
    }

    return isTrue;
}

int main(void)
{
    cin >> T;

    while (T--) {
        cin >> V >> E;
        arr = vector<vector<int>>(V + 1);

        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;

            arr[x].push_back(y);
            arr[y].push_back(x);
        }

        for (int i = 1; i <= V; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                paintColor(i);
            }
        }

        bool isTrue;
        for (int i = 1; i <= V; i++) {
            if (colorCheck[i] == false) {
                colorCheck[i] = true;
                isTrue = confirmColor(i);

                if (isTrue == false) {
                    cout << "NO" << '\n';
                    break;
                }
            }
        }
        if (isTrue == true) {
            cout << "YES" << '\n';
        }

        for (int i = 1; i <= V; i++) {
            colorCheck[i] = false;
            color[i] = 0;
        }
    }
}