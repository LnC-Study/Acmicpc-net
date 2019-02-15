#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int max_town = 16;
const int inf = 987654321;

vector<vector<int>>path;
int N, start;
int cache[max_town][1 << max_town];

int TSP(int node, int visit) {

	//모든 노드를 방문 했을 때
	if (visit == (1 << N) - 1)
		return path[node][start];

	int& ret = cache[node][visit];
	if (ret != -1)
		return ret;

	ret = inf;
	for (int i = 0; i < N; i++) {
		//미리 방문하지 않은 곳 이라면!
		if(!((1 << i) & visit))
			ret = min(ret, TSP(i,(1 << i) + visit) + path[node][i]);
	}

	return ret;
}

void data_in() {

	freopen("input.txt", "r", stdin);

	scanf("%d ", &N);

	path = vector<vector<int>>(N, vector<int>(N, -1));
	memset(cache, -1, sizeof(int)*max_town*((1 << max_town) - 1));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int p;
			scanf("%d ", &p);
			path[i][j] = p ? p : inf;
		}

	start = 0;
	int answer = TSP(0, 1);

	printf("%d ", answer);
}

int main() {
	data_in();
}
