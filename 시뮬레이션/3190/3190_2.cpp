#include <iostream>
#include <deque>

using namespace std;

int idx[4] = {0, 1, 0, -1};
int idy[4] = {1, 0, -1, 0};
int N;
int map[101][101];
int visited[101][101];
pair<int, char> change[101];
deque<pair<int, int>> q;

int dir; //현재 방향

int main()
{
	int K, L;
	int a, b;
	char c;
	int i, j;
	int sec = 0; //초정보
	int x, y;
	int tmpx, tmpy;
	pair<int, int> tmp;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			map[i][j] = 0;

	scanf("%d", &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = 1; //사과위치, 0부터 index사용하면서 [a][b]로 해둬서 틀렸었다.
	}

	scanf("%d", &L);

	for (i = 0; i < L; i++)
	{
		scanf("%d %c", &a, &c);
		change[i].first = a;
		change[i].second = c; //바꿀 방향과 초 정보
	}

	dir = 0; //처음 방향은 오른쪽

	x = 0;
	y = 0;

	q.push_back(make_pair(x, y));

	a = 0;

	while (q.size() > 0)
	{
		sec++; //1초가 지났음

		tmp = q.back(); //젤 마지막에 들어갔던거 나옴

		x = tmp.first + idx[dir];
		y = tmp.second + idy[dir];

		if (visited[x][y] == 1 ||
			x < 0 || x >= N ||
			y < 0 || y >= N)
			break; //벽을 박아서 종료

		q.push_back(make_pair(x, y));

		visited[x][y] = 1;

		if (map[x][y] == 1)
		{
			map[x][y] = 0;
		}
		else
		{
			tmp = q.front();
			visited[tmp.first][tmp.second] = 0;
			q.pop_front();
		}

		if (a < L && sec == change[a].first) //방향바꿔야하면
		{
			if (change[a++].second == 'D')
				dir = (dir + 1 + 4) % 4;
			else
				dir = (dir - 1 + 4) % 4;
		}
	}

	printf("%d\n", sec);
}
