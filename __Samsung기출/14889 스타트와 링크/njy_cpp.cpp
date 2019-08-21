#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, ans = INF;
int S[21][21];
vector<int> teamA;
vector<int> teamB;

void solve(int idx)
{
	if (idx > N) {
		int sumA = 0, sumB = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sumA += (S[teamA[i]][teamA[j]] + S[teamA[j]][teamA[i]]);
				sumB += (S[teamB[i]][teamB[j]] + S[teamB[j]][teamB[i]]);
			}
		}
		ans = min(ans, abs(sumA - sumB));
		return;
	}

	if (teamA.size() != N / 2) {
		teamA.push_back(idx);
		solve(idx + 1);
		teamA.pop_back();
	}
	if (teamB.size() != N / 2) {
		teamB.push_back(idx);
		solve(idx + 1);
		teamB.pop_back();
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	teamA.push_back(1);
	solve(2);
	printf("%d\n", ans);
	return 0;
}