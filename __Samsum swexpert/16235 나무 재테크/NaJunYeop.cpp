#include <cstdio>
#include <vector>
using namespace std;

int N, M, K;
vector < vector< vector< pair<int, int> > > > tree(11, vector< vector< pair<int, int> > >(11));
int A[11][11];
int nutri[11][11];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main()
{
	int x, y, z, tx, ty, dsum, dead, alive, needed, year = 0, ans = 0;
	int age, cnt;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			nutri[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		tree[x][y].push_back(make_pair(z, 1));
	}

	while (1) {
		year++;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dsum = 0;
				for (int k = tree[i][j].size() - 1; k > -1; k--) {
					age = tree[i][j][k].first, cnt = tree[i][j][k].second;
					needed = age * cnt;
					if (nutri[i][j] - needed >= 0) {
						nutri[i][j] -= needed;
						tree[i][j][k].first++;
					}
					else {
						alive = nutri[i][j] / age;
						dead = cnt - alive;

						nutri[i][j] -= (age * alive);
						dsum += ((age / 2) * dead);

						if (alive == 0) tree[i][j].erase(tree[i][j].begin() + k);
						else {
							tree[i][j][k].second = alive;
							tree[i][j][k].first++;
						}
					}
				}
				nutri[i][j] += (dsum + A[i][j]);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k].first % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							tx = i + dx[d], ty = j + dy[d];
							if (tx < 1 || tx > N || ty < 1 || ty > N) continue;
							if (tree[tx][ty].size() == 0 || tree[tx][ty].back().first != 1) tree[tx][ty].push_back(make_pair(1, tree[i][j][k].second));
							else tree[tx][ty].back().second += tree[i][j][k].second;
						}
					}
				}
			}
		}
		if (year == K) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					for (int k = 0; k < tree[i][j].size(); k++) {
						ans += tree[i][j][k].second;
					}
				}
			}
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}