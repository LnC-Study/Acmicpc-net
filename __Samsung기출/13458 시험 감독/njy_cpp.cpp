#include <cstdio>
using namespace std;

int N, B, C;
int p[1000001];
long long ans;

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) { scanf("%d", &p[i]); }
	scanf("%d %d", &B, &C);

	for (int i = 1; i <= N; i++) {
		if (p[i] - B >= 0) p[i] -= B;
		else p[i] = 0;
		ans++;
	}

	for (int i = 1; i <= N; i++) {
		ans += (p[i] / C);
		if ((p[i] % C) > 0) ans++;
	}

	printf("%lld\n", ans);
	return 0;
}