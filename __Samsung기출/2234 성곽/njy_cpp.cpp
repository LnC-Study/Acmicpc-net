#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int M, N;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int m[51][51];
bool v[51][51];
int room = 0;

int bfs()
{
	int ret = -1, tmp;
	int x, y, tx, ty;
	queue< pair<int, int> > q;

	memset(v, false, sizeof(v));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!v[i][j]) {
				tmp = 1;
				room++, v[i][j] = true, q.push(make_pair(i, j));
				while (!q.empty()) {
					x = q.front().first, y = q.front().second, q.pop();

					for (int d = 0; d < 4; d++) {
						tx = x + dx[d], ty = y + dy[d];
						if ((m[x][y] & (1 << d)) || v[tx][ty]) continue;
						tmp++, v[tx][ty] = true, q.push(make_pair(tx, ty));
					}
				}
				ret = max(ret, tmp);
			}
		}
	}
	return ret;
}
int main()
{
	int x, y, tx, ty;
	int maxroom = -1, maxroom2 = -1;
	
	scanf("%d %d", &M, &N);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	
	maxroom = bfs();

	printf("%d\n", room);
	printf("%d\n", maxroom);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int d = 0; d < 4; d++) {
				x = i + dx[d], y = j + dy[d];
				if (!(m[i][j] & (1 << d)) || x < 1 || x > N || y < 1 || y > N) continue;
				memset(v, false, sizeof(v));
				m[i][j] ^= (1 << d), m[x][y] ^= (1 << (d + 2) % 4);
				maxroom2 = max(maxroom2, bfs());
				m[i][j] |= (1 << d), m[x][y] |= (1 << (d + 2) % 4);
			}
		}
	}
	printf("%d\n", maxroom2);
	return 0;
}