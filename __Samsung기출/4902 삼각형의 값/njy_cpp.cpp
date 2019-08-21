#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN -2e9
using namespace std;

int N, ans;
int triangle[401][801];
int asum[401][801];

void solve(int x, int yleft, int yright, int sum)
{
	if (x > N || x < 1 || yleft < 1 || yright >(2 * x) - 1) return;

	sum += asum[x][yright] - asum[x][yleft - 1];

	ans = max(ans, sum);

	if (yleft % 2 == 1) solve(x + 1, yleft, yright + 2, sum);
	else solve(x - 1, yleft - 2, yright, sum);
}
int main()
{
	int idx = 0;
	while (1) {
		idx++, ans = MIN;
		scanf("%d", &N);
		if (!N) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= (i * 2) - 1; j++) {
				scanf("%d", &triangle[i][j]);
				asum[i][j] = asum[i][j - 1] + triangle[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= (i * 2) - 1; j++) {
				solve(i, j, j, 0);
			}
		}
		printf("%d. %d\n", idx, ans);
	}
	return 0;
}