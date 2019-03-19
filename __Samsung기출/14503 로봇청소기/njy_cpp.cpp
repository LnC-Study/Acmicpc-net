#include <cstdio>
using namespace std;

int N, M;
int m[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
int x, y, d;

int solve()
{
	int tx, ty, td, ans = 0;

	while (1) {
		m[x][y] = 2, ans++;
		td = d;
		while (1) {
			td = (td + 3) % 4, tx = x + dx[td], ty = y + dy[td];

			if (m[tx][ty] == 0) {
				x = tx, y = ty, d = td;
				break;
			}
			else {
				if (td == d) {
					tx = x - dx[d], ty = y - dy[d];
					if (m[tx][ty] == 1) return ans;
					else {
						x = tx, y = ty;
						continue;
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &x, &y, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	printf("%d\n", solve());
	return 0;
}