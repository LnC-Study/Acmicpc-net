#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 3000
#define INF 987654321
using namespace std;

vector<vector<int>> adj;
int over[MAXN + 1];
int cache[MAXN + 1];

int N;

int not_friend_in_range(int start, int end) {

	int ret = 0;

	for (int i = start; i <= end; i++) {
		int j = over[start];

		if (j == -1)
			continue;

		if (!adj[i][j])
			break;

		if (adj[i][j] <= end) {
			ret += adj[i][j] - (start + 1);

			for (j += 1; j < adj[i].size(); j++) {
				if (adj[i][j] > end)
					break;

				ret += adj[i][j] - adj[i][j - 1];
			}
		}
		
	}

	return ret;
}

int friend_not_range(int start, int end) {

	int ret = 0;

	for (int i = start; i <= end; i++)
		for (int j = 0; j < adj[i].size(); j++)
			if (adj[i][j] > end) {
				ret += adj[i].size() - j - 1;
				break;
			}

	return ret;
}

int min_score(int idx) {

	if (idx == N)
		return 0;

	int &ret = cache[idx];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = idx + 1; i <= N; i++) {
		
		ret = min(ret, not_friend_in_range(idx, i - 1) + friend_not_range(idx, i - 1) + min_score(i));

	}

	return ret;

}

void data_in() {

	freopen("input.txt", "r", stdin);

	scanf("%d ", &N);
	
	adj = vector<vector<int>>(N + 1);
	

	memset(cache, -1, sizeof(int) * (MAXN + 1));
	memset(over, -1, sizeof(int) * (MAXN + 1));

	for (int i = 1; i <= N; i++) {
		int value = 1;

		while (value) {
			scanf("%d ", &value);

			if (value > i && over[i] == -1)
				over[i] = adj[i].size();

			adj[i].push_back(value);
		}
	}

	printf("%d ", min_score(1));

}

int main() {

	data_in();

}
