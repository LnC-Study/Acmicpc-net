#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ans = 0;
int board[21][21];
bool meet[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void gmax(int(*b)[21])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, b[i][j]);
		}
	}
}

void move(int(*b)[21], int r, int c, int dir)
{
	int val = b[r][c];
	int tr = r, tc = c;
	bool hit = false;

	b[r][c] = 0;

	while (1) {

		tr += dx[dir], tc += dy[dir];

		if (tr < 1 || tr > N || tc < 1 || tc > N) {
			tr -= dx[dir], tc -= dy[dir];
			b[tr][tc] = val;
			if (hit) meet[tr][tc] = true;
			return;
		}

		if (b[tr][tc] != 0) {
			if (b[tr][tc] == val) {
				if ((!meet[tr][tc]) && (!hit)) {
					hit = true;
					val *= 2;
					b[tr][tc] = 0;
				}
				else {
					tr -= dx[dir], tc -= dy[dir];
					b[tr][tc] = val;
					if (hit) meet[tr][tc] = true;
					return;
				}
			}
			else {
				tr -= dx[dir], tc -= dy[dir];
				b[tr][tc] = val;
				if (hit) meet[tr][tc] = true;
				return;
			}
		}
	}
}

void direction(int(*b)[21], int dir)
{
	if ((dir == 0) || (dir == 3)) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dir == 0) if (b[j][i] != 0) move(b, j, i, dir);
				if (dir == 3) if (b[i][j] != 0) move(b, i, j, dir);
			}
		}
	}
	if ((dir == 1) || (dir == 2)) {
		for (int i = 1; i <= N; i++) {
			for (int j = N; j >= 1; j--) {
				if (dir == 1) if (b[i][j] != 0) move(b, i, j, dir);
				if (dir == 2) if (b[j][i] != 0) move(b, j, i, dir);
			}
		}
	}
}

void solve(int cnt, int(*b)[21], int dir)
{
	int btmp[21][21];

	memcpy(btmp, b, sizeof(btmp));

	if (cnt > 5) {
		gmax(btmp);
		return;
	}

	if (cnt > 0) {
		memset(meet, false, sizeof(meet));
		direction(btmp, dir);
	}

	for (int i = 0; i < 4; i++) solve(cnt + 1, btmp, i);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	solve(0, board, 0);
	printf("%d\n", ans);
	return 0;
}