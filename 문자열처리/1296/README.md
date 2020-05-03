# 백준 1296 - 데이트

## 문제
오민식은 자기가 좋아하는 여자 N명 중에 한 명과 함께 데이트하러 나가고 싶어한다.
하지만 N명 모두를 사랑하는 오민식에게는 한 명을 선택하고 나머지 여자를 버리는 것은 슬픈 결정이기 때문에 누구를 선택해야 할지 고민에 빠졌다.
마침 오민식은 사랑계산기를 얻었다. 사랑계산기는 두 사람의 이름을 이용해서 두 사람이 성공할 확률을 계산해 준다. 사랑계산기는 다음과 같이 작동한다.
위의 개수를 모두 계산 한 후에 확률 계산은 다음과 같이 한다.
((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E)) mod 100
오민식의 영어 이름과 나머지 여자들의 이름이 주어졌을 때, 오민식과 성공할 확률이 가장 높은 여자의 이름을 출력하는 프로그램을 작성하시오. 여러명일 때에는 알파벳으로 가장 앞서는 이름을 출력하면 된다.


## 입력
첫째 줄에 오민식의 영어 이름이 주어진다. 둘째 줄에는 좋아하는 여자가 몇 명인지 N이 주어지고, 셋째 줄부터 N개의 줄에 여자의 이름이 하나 씩 주어진다. N은 50보다 작거나 같고, 모든 이름은 알파벳 대문자로만 구성되어 있고 모두 길어야 20글자이다.

## 출력
오민식이 선택한 여자의 이름을 출력한다.

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

string name;
int ohminsick[26];
pair<int, string> arr[55];
int n;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(void) {
    cin >> name >> n;

    for (int i = 0; i < name.size(); i++) {
        ohminsick[name[i] - 'A']++;
    }

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        int spelling[26];
        memset(spelling, 0, sizeof(spelling));
        for (int j = 0; j < temp.size(); j++) {
            spelling[temp[j] - 'A']++;
        }

        int L = spelling['L' - 'A'] + ohminsick['L' - 'A'];
        int O = spelling['O' - 'A'] + ohminsick['O' - 'A'];
        int V = spelling['V' - 'A'] + ohminsick['V' - 'A'];
        int E = spelling['E' - 'A'] + ohminsick['E' - 'A'];

        int total = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        arr[i] = {total, temp};
    }

    sort(arr, arr + n, cmp);

    cout << arr[0].second << '\n';
}
```

## 파이썬 코드
```python
def returnLOVENum(name):
    L = 0
    O = 0
    V = 0
    E = 0
    for c in name:
        if(c == 'L'):
            L += 1
        if(c == 'O'):
            O += 1
        if(c == 'V'):
            V += 1
        if(c == 'E'):
            E += 1

    return L, O, V, E


ohminsic = input()
n = int(input())
ohminsic_L, ohminsic_O, ohminsic_V, ohminsic_E = returnLOVENum(ohminsic)

name_list = []
for i in range(n):
    name_list.append(input())
name_list = sorted(name_list)


max_value = -1
max_name = ""
for name in name_list:
    L, O, V, E = returnLOVENum(name)

    value = ((ohminsic_L + L + ohminsic_O + O) *
             (ohminsic_L + L + ohminsic_V + V) *
             (ohminsic_L + L + ohminsic_E + E) *
             (ohminsic_O + O + ohminsic_V + V) *
             (ohminsic_O + O + ohminsic_E + E) *
             (ohminsic_V + V + ohminsic_E + E))

    value %= 100
    if(max_value < value):
        max_value = value
        max_name = name

print(max_name)
```

## 자바 코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String minsik = br.readLine().trim();
        int minsik_arr[] = new int[26];

        for (int i = 0; i < minsik.length(); i++) {
            minsik_arr[minsik.charAt(i) - 'A']++;
        }

        int n = Integer.parseInt(br.readLine().trim());
        ArrayList<String> name_list = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            name_list.add(br.readLine().trim());
        }
        Collections.sort(name_list);

        int max_value = -1;
        String max_name = "";
        for (int i = 0; i < name_list.size(); i++) {
            String name = name_list.get(i);
            int arr[] = new int[26];
            for (int j = 0; j < name.length(); j++) {
                arr[name.charAt(j) - 'A']++;
            }

            int L = minsik_arr['L' - 'A'] + arr['L' - 'A'];
            int O = minsik_arr['O' - 'A'] + arr['O' - 'A'];
            int V = minsik_arr['V' - 'A'] + arr['V' - 'A'];
            int E = minsik_arr['E' - 'A'] + arr['E' - 'A'];

            int value = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E));
            value %= 100;

            if (max_value < value) {
                max_value = value;
                max_name = name;
            }
        }

        System.out.println(max_name);

        br.close();
    }
}
```