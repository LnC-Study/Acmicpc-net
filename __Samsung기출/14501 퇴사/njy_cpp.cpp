#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN -2e9
#pragma warning(disable:4996)
using namespace std;

int N;
int T[16];
int P[16];
int dp[21];

int solve(int cur)
{
	int &ret = dp[cur];
	if (ret > 0) return ret;
	if (cur == N + 1) return ret = 0;
	else if (cur > N + 1) return ret = MIN;

	return ret = max(solve(cur + T[cur]) + P[cur], solve(cur + 1));
}
int main()
{
	int t, p;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d", &T[i], &P[i]);
	memset(dp, -1, sizeof(dp));

	printf("%d\n", solve(1));
	return 0;
}