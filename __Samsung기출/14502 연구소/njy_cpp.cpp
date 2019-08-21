#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, ans = -1;
int m[9][9];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector< pair<int, int> > virus;

int spread()
{
	int tmp[9][9];
	int x, y, tx, ty, ret = 0;
	queue< pair<int, int> > q;

	memcpy(tmp, m, sizeof(tmp));

	for (int i = 0; i < virus.size(); i++) {
		x = virus[i].first, y = virus[i].second, q.push(make_pair(x, y));
		while (!q.empty()) {
			x = q.front().first, y = q.front().second, q.pop();

			for (int d = 0; d < 4; d++) {
				tx = x + dx[d], ty = y + dy[d];
				if (tx < 0 || tx > N - 1 || ty < 0 || ty > M - 1 || tmp[tx][ty]) continue;
				tmp[tx][ty] = 2, q.push(make_pair(tx, ty));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!tmp[i][j]) ret++;
		}
	}
	return ret;
}
void solve(int row, int col, int cnt)
{
	if (cnt == 3) {
		ans = max(ans, spread());
		return;
	}
	for (int i = row; i < N; i++) {
		int j = row == i ? col : 0;
		for (; j < M; j++) {
			if (!m[i][j]) {
				m[i][j] = 1;
				solve(i, j, cnt + 1);
				m[i][j] = 0;
			}
		}
	}
}
int main()
{
	int val;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &val);
			m[i][j] = val;
			if (val == 2) virus.push_back(make_pair(i, j));
		}
	}
	solve(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}