#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int b[501][501];
int ans = -1;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &b[i][j]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N && j + 1 < M) ans = max(ans, b[i][j] + b[i][j + 1] + b[i + 1][j] + b[i + 1][j + 1]);
			if (j + 3 < M) ans = max(ans, b[i][j] + b[i][j + 1] + b[i][j + 2] + b[i][j + 3]);
			if (i + 3 < N) ans = max(ans, b[i][j] + b[i + 1][j] + b[i + 2][j] + b[i + 3][j]);
			if (i + 2 < N && j + 1 < M) {
				ans = max(ans, b[i][j] + b[i + 1][j] + b[i + 2][j] + b[i + 2][j + 1]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i + 1][j + 1] + b[i + 2][j + 1]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i + 1][j] + b[i + 2][j]);
				ans = max(ans, b[i][j] + b[i + 1][j] + b[i + 1][j + 1] + b[i + 2][j + 1]);
				ans = max(ans, b[i][j] + b[i + 1][j] + b[i + 1][j + 1] + b[i + 2][j]);
			}
			if (i - 2 > -1 && j + 1 < M) ans = max(ans, b[i][j] + b[i][j + 1] + b[i - 1][j + 1] + b[i - 2][j + 1]);
			if (i + 1 < N && j + 2 < M) {
				ans = max(ans, b[i][j] + b[i + 1][j] + b[i][j + 1] + b[i][j + 2]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i][j + 2] + b[i + 1][j + 2]);
				ans = max(ans, b[i][j] + b[i + 1][j] + b[i + 1][j + 1] + b[i + 1][j + 2]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i + 1][j + 1] + b[i][j + 2]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i + 1][j + 1] + b[i + 1][j + 2]);
			}
			if (i - 1 > -1 && j + 2 < M) {
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i][j + 2] + b[i - 1][j + 2]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i - 1][j + 1] + b[i - 1][j + 2]);
				ans = max(ans, b[i][j] + b[i][j + 1] + b[i - 1][j + 1] + b[i][j + 2]);
			}
			if (i - 2 > -1 && j + 1 < M) ans = max(ans, b[i][j] + b[i - 1][j] + b[i - 1][j + 1] + b[i - 2][j + 1]);
			if (i - 1 > -1 && i + 1 < N && j + 1 < M) ans = max(ans, b[i][j] + b[i][j + 1] + b[i - 1][j + 1] + b[i + 1][j + 1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
