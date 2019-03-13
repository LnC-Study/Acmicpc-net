#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct _fish {
	int x;
	int y;
	int dist;
} fish;
typedef struct _node {
	int x;
	int y;
	int size;
	int ate;
} node;

int m[21][21];
bool v[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, ans = 0;
node shark;

bool move()
{
	int x, y, dist, tx, ty, tdist;
	queue<fish> q;
	fish eat, tmp;
	memset(v, false, sizeof(v));

	eat.dist = -1;
	tmp.x = shark.x, tmp.y = shark.y, tmp.dist = 0;
	v[shark.x][shark.y] = true;
	q.push(tmp);

	while (!q.empty()) {
		x = q.front().x, y = q.front().y, dist = q.front().dist;
		q.pop();

		if ((eat.dist != -1) && (eat.dist <= dist)) break;

		for (int d = 0; d < 4; d++) {
			tx = x + dx[d], ty = y + dy[d], tdist = dist + 1;

			if (tx < 1 || tx > N || ty < 1 || ty > N || v[tx][ty] || m[tx][ty] > shark.size) continue;

			v[tx][ty] = true;

			if (m[tx][ty] == 0 || m[tx][ty] == shark.size) {
				tmp.x = tx, tmp.y = ty, tmp.dist = tdist;
				q.push(tmp);
			}
			else {
				if (eat.dist == -1) eat.x = tx, eat.y = ty, eat.dist = tdist;
				else {
					if (eat.x > tx) eat.x = tx, eat.y = ty;
					if (eat.x == tx) {
						if (eat.y > ty) eat.y = ty;
					}
				}
			}
		}
	}
	if (eat.dist == -1) return false;
	else {
		shark.x = eat.x, shark.y = eat.y;
		ans += eat.dist;
		shark.ate++;
		m[shark.x][shark.y] = 0;

		if (shark.ate == shark.size) {
			shark.size++;
			shark.ate = 0;
		}
		return true;
	}
}
int main()
{
	int val;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &val);
			if (val == 9) shark.x = i, shark.y = j, shark.size = 2, shark.ate = 0, m[i][j] = 0;
			else m[i][j] = val;
		}
	}
	while (1) {
		if (!move()) break;
	}
	printf("%d\n", ans);
	return 0;
}