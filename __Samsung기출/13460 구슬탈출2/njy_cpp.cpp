#include <cstdio>
#include <algorithm>
#define MAX 2e9
using namespace std;

int N, M;
char m[11][11];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = MAX;
int limit;

void solve(int rx, int ry, int bx, int by, int cnt, int dir)
{
	int rdist = 0, bdist = 0;
	if (cnt > 10) return;
	if (cnt > 0) {
		while (m[bx + dx[dir]][by + dy[dir]] != '#') {
			bx += dx[dir], by += dy[dir], bdist++;
			if (m[bx][by] == 'O') return;
		}
		while (m[rx + dx[dir]][ry + dy[dir]] != '#') {
			rx += dx[dir], ry += dy[dir], rdist++;
			if (m[rx][ry] == 'O') {
				ans = min(ans, cnt);
				return;
			}
		}
		if ((rx == bx) && (ry == by)) {
			if (rdist < bdist) bx -= dx[dir], by -= dy[dir];
			else rx -= dx[dir], ry -= dy[dir];
		}
	}
	for (int d = 0; d < 4; d++) {
		if (d == dir || d == (dir + 2) % 4) continue;
		solve(rx, ry, bx, by, cnt + 1, d);
	}
}
int main()
{
	int rx, ry, bx, by;
	char line[12];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &line);
		for (int j = 0; j < M; j++) {
			m[i][j] = line[j];
			if (line[j] == 'R') rx = i, ry = j;
			if (line[j] == 'B') bx = i, by = j;
		}
	}
	solve(rx, ry, bx, by, 0, -3);
	printf("%d\n", ans == MAX ? -1 : ans);
	return 0;
}