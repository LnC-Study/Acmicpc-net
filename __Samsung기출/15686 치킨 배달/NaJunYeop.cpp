#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, ans = INF;
vector< pair<int, int> > home;
vector< pair<int, int> > chicken;
bool v[14];

int gdist(pair<int, int> &a, pair<int, int> &b) { return abs(a.first - b.first) + abs(a.second - b.second); }
int calc()
{
	int gmin, ret = 0;

	for (int i = 0; i < home.size(); i++) {
		gmin = INF;
		for (int j = 0; j < chicken.size(); j++) {
			if (v[j]) gmin = min(gmin, gdist(home[i], chicken[j]));
		}
		ret += gmin;
	}
	return ret;
}
void solve(int idx, int cnt, int limit)
{
	if (cnt == limit) {
		ans = min(ans, calc());
		return;
	}
	for (int i = idx + 1; i < chicken.size(); i++) {
		v[i] = true;
		solve(i, cnt + 1, limit);
		v[i] = false;
	}
}
int main()
{
	int val;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &val);
			if (val == 1) home.push_back(make_pair(i, j));
			if (val == 2) chicken.push_back(make_pair(i, j));
		}
	}
	solve(-1, 0, M);
	printf("%d\n", ans);
	return 0;
}