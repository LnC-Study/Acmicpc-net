#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, ans = INF;
int m[9][9];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector< pair<int, int> > cctv;

int gans(int(*a)[9])
{
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i][j] == 0) ret++;
		}
	}
	return ret;
}
void recording(pair<int, int> p, int dir, int(*a)[9])
{
	int x = p.first;
	int y = p.second;

	while (1) {
		x += dx[dir], y += dy[dir];
		if (x < 1 || x > N || y < 1 || y > M || a[x][y] == 6) return;
		if (a[x][y] == 0) a[x][y] = 7;
	}
}
void typecheck(int idx, int dir, int type, int(*a)[9])
{
	recording(cctv[idx], dir, a);

	if (type == 2) recording(cctv[idx], (dir + 2) % 4, a);
	else if (type == 3) recording(cctv[idx], (dir + 3) % 4, a);
	else if (type == 4) {
		recording(cctv[idx], (dir + 2) % 4, a);
		recording(cctv[idx], (dir + 3) % 4, a);
	}
	else if (type == 5) {
		recording(cctv[idx], (dir + 1) % 4, a);
		recording(cctv[idx], (dir + 2) % 4, a);
		recording(cctv[idx], (dir + 3) % 4, a);
	}
}
void solve(int idx, int(*a)[9])
{
	int tmp[9][9];
	int type;

	if (idx == cctv.size()) {
		ans = min(ans, gans(a));
		return;
	}

	type = m[cctv[idx].first][cctv[idx].second];

	if (type == 1 || type == 3 || type == 4) {
		for (int d = 0; d < 4; d++) {
			memcpy(tmp, a, sizeof(tmp));
			typecheck(idx, d, type, tmp);
			solve(idx + 1, tmp);
		}
	}
	else if (type == 2) {
		for (int d = 0; d < 2; d++) {
			memcpy(tmp, a, sizeof(tmp));
			typecheck(idx, d, type, tmp);
			solve(idx + 1, tmp);
		}
	}
	else {
		memcpy(tmp, a, sizeof(tmp));
		typecheck(idx, 0, type, tmp);
		solve(idx + 1, tmp);
	}
}
int main()
{
	int val;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &val);
			m[i][j] = val;
			if (val > 0 && val < 6) cctv.push_back(make_pair(i, j));
		}
	}

	solve(0, m);
	printf("%d\n", ans);
	return 0;
}