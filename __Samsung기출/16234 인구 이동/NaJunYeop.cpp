#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L, R;
int m[51][51];
int nsum[2501];
int psum[2501];
int nval[2501];
int check[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;
queue< pair<int, int> > q;

void solve()
{
	int grp, r, c, tr, tc, gap;

	while (1) {
		grp = 1;
		memset(check, 0, sizeof(check));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i][j] == 0) {
					q.push(make_pair(i, j)), check[i][j] = grp;
					nsum[grp] = 1, psum[grp] = m[i][j];

					while (!q.empty()) {
						r = q.front().first, c = q.front().second, q.pop();

						for (int d = 0; d < 4; d++) {
							tr = r + dx[d], tc = c + dy[d];
							if (tr < 1 || tr > N || tc < 1 || tc > N || check[tr][tc] != 0) continue;

							gap = abs(m[r][c] - m[tr][tc]);
							if ((gap >= L) && (gap <= R)) {
								q.push(make_pair(tr, tc));
								check[tr][tc] = grp;
								nsum[grp]++, psum[grp] += m[tr][tc];
							}
						}
					}
					nval[grp] = psum[grp] / nsum[grp];
					grp++;
				}
			}
		}

		grp--;

		if (grp == N * N) return;
		else {
			ans++;
			int g;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					g = check[i][j];
					if (g != 0) m[i][j] = nval[g];
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	solve();
	printf("%d\n", ans);
	return 0;
}