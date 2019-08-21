#include <cstdio>
using namespace std;

int N, M, H;
int ladder[31][11];

bool play()
{
	int r, c;
	for (int col = 1; col <= N; col++) {
		r = 1, c = col;
		while (1) {
			c += ladder[r][c], r++;
			if (r > H) {
				if (c != col) return false;
				else break;
			}
		}
	}
	return true;
}
bool solve(int row, int cnt, int limit)
{
	if (cnt == limit) return play();

	for (int i = row; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (ladder[i][j] == 0 && ladder[i][j + 1] == 0) {
				ladder[i][j] = 1, ladder[i][j + 1] = -1;
				if (solve(i, cnt + 1, limit)) return true;
				ladder[i][j] = 0, ladder[i][j + 1] = 0;
			}
		}
	}
	return false;
}
int main()
{
	int row, idx;
	scanf("%d %d %d", &N, &M, &H);

	if (M == 0) printf("0\n");
	else {
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &row, &idx);
			ladder[row][idx] = 1;
			ladder[row][idx + 1] = -1;
		}
		for (int limit = 0; limit <= 3; limit++) {
			if (solve(1, 0, limit)) {
				printf("%d\n", limit);
				return 0;
			}
		}
		printf("-1\n");
	}
	return 0;
}