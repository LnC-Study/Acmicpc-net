#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, L;
int map[101][101];
queue< pair<int, int> > q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int command[10001];

int play(int dir)
{
	int t = 0;
	int r = 1, c = 1;
	pair<int, int> dq;

	map[r][c] = 2, q.push(make_pair(r, c));

	while (1) {

		r += dx[dir], c += dy[dir];
		t++;

		if (r < 1 || r > N || c < 1 || c > N) return t;
		if (map[r][c] == 2) return t;

		if (map[r][c] != 1) {
			dq = q.front(), q.pop();
			map[dq.first][dq.second] = 0;
		}

		map[r][c] = 2, q.push(make_pair(r, c));

		if (command[t] == 1) dir = (dir + 3) % 4;
		if (command[t] == 2) dir = (dir + 1) % 4;
	}
}

int main()
{
	int r, c, t;
	char chr;

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &r, &c);
		map[r][c] = 1;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &t, &chr);
		if (chr == 'L') command[t] = 1;
		if (chr == 'D') command[t] = 2;
	}

	printf("%d\n", play(1));

	return 0;
}