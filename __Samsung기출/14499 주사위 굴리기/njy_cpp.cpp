#include <cstdio>
using namespace std;

int N, M, x, y, K;
int m[21][21];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int dice[7];

void north(int d)
{
	int tmp;
	tmp = dice[2], dice[2] = dice[1], dice[1] = dice[5], dice[5] = dice[6], dice[6] = tmp;
}
void east(int d)
{
	int tmp;
	tmp = dice[3], dice[3] = dice[1], dice[1] = dice[4], dice[4] = dice[6], dice[6] = tmp;
}
void west(int d)
{
	int tmp;
	tmp = dice[4], dice[4] = dice[1], dice[1] = dice[3], dice[3] = dice[6], dice[6] = tmp;
}
void south(int d)
{
	int tmp;
	tmp = dice[6], dice[6] = dice[5], dice[5] = dice[1], dice[1] = dice[2], dice[2] = tmp;
}
int main()
{
	int tx, ty, dir;

	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &m[i][j]);
	for (int i = 0; i < K; i++) {
		scanf("%d", &dir);
		tx = x + dx[dir], ty = y + dy[dir];
		if (tx < 0 || tx > N - 1 || ty < 0 || ty > M - 1) continue;
		x = tx, y = ty;
		switch (dir) {
		case 1: east(dir); break;
		case 2: west(dir); break;
		case 3: north(dir); break;
		case 4: south(dir); break;
		}
		if (m[x][y] == 0) m[x][y] = dice[6];
		else dice[6] = m[x][y], m[x][y] = 0;
		printf("%d\n", dice[1]);
	}
	return 0;
}