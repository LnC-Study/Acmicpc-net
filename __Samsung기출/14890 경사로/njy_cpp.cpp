#include <cstdio>
#include <cmath>
using namespace std;

int N, L, ans = 0;
int m1[101][101];
int m2[101][101];

void solve(int(*m)[101])
{
	int prev, cur, cnt, gap, col;

	for (int row = 1; row <= N; row++) {
		col = 1;
		prev = m[row][col], col++, cnt = 1;

		while (1) {
			cur = m[row][col];
			gap = abs(prev - cur);

			if (gap == 0) cnt++;
			else if (gap == 1) {
				if (prev < cur) {
					if (cnt >= L) cnt = 1;
					else break;
				}
				else {
					bool check = true;
					int height = m[row][col];
					if (col + L - 1 > N) break;
					for (int idx = col + 1; idx <= (col + L - 1); idx++) {
						if (m[row][idx] != height) {
							check = false;
							break;
						}
					}
					if (check) cnt = 0, col += (L - 1);
					else break;
				}
			}
			else break;

			prev = m[row][col];
			col++;
			if (col > N) {
				ans++;
				break;
			}
		}
	}
}
int main()
{
	int val;
	int m2[101][101];
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &val);
			m1[i][j] = val;
			m2[j][i] = val;
		}
	}
	solve(m1);
	solve(m2);
	printf("%d\n", ans);
	return 0;
}