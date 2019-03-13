#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 21
#pragma warning(disable:4996)
using namespace std;

int N, M, T, ans;
int m[MAX][MAX];
bool v[MAX][MAX];
int cost[MAX + 1];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void rcost() { for (int i = 1; i <= MAX + 1; i++) cost[i] = (i * i) + ((i - 1) * (i - 1)); }
void solve(int x, int y)
{
	queue< pair<int, int> > q;
	int bcnt = (m[x][y] == 1) ? 1 : 0;
	int r, c, tr, tc, k = 1;
	int qsize;

	memset(v, false, sizeof(v));
	v[x][y] = true;

	q.push(make_pair(x, y));

	while (!q.empty()) {

		if ((M * bcnt) - cost[k] >= 0) ans = max(ans, bcnt);

		k++;

		if (k > N + 1) return;

		qsize = q.size();
		while (qsize > 0) {
			r = q.front().first, c = q.front().second, q.pop();

			for (int d = 0; d < 4; d++) {
				tr = r + dx[d], tc = c + dy[d];

				if (tr < 1 || tr > N || tc < 1 || tc > N || v[tr][tc]) continue;

				v[tr][tc] = true;
				if (m[tr][tc] == 1) bcnt++;
				q.push(make_pair(tr, tc));
			}
			qsize--;
		}
	}
}
int main()
{
	rcost();
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &m[i][j]);
			}
		}

		ans = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				solve(i, j);
			}
		}

		printf("#%d %d\n", t, ans);
	}
	return 0;
}