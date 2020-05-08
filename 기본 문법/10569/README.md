# 백준 10569 - 다면체

## 문제

수학자가 구를 깎아서 볼록다면체를 만들었다. 이 수학자는 임의의 볼록다면체에 대해 (꼭짓점의 수) - (모서리의 수) + (면의 수) = 2가 성립한다는 것을 알고 있다. 그래서 구를 깎는 게 취미인 이 사람은 꼭짓점, 모서리와 면의 수를 기록할 때 꼭짓점과 모서리의 수만 세고 면의 수는 세지 않는다.


## 입력
첫 번째 줄에 1 이상 100 이하의 자연수 T가 주어진다.
다음 T개의 줄에 4 이상 100 이하의 자연수 V와 E가 공백을 사이에 두고 주어진다. V와 E는 각각 꼭짓점의 개수와 모서리의 개수이다.

## 출력
각 V와 E에 대해 볼록다면체의 면의 수를 한 줄에 하나씩 출력한다.

## 파이썬 코드
```python
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(2+b-a)
```

## 자바 코드
```java
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String s_arr[] = br.readLine().split(" ");
            int a = Integer.parseInt(s_arr[0]);
            int b = Integer.parseInt(s_arr[1]);
            System.out.println(2 + b - a);
        }

        br.close();
    }
}
```