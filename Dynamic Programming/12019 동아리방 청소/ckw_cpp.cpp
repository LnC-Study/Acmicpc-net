#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = 987654321;
int cache[101][101][2001];
int N;
vector<int> stNum;
int min_unplea(int day, int leftM, int dirty) {

	if (leftM < 0)
		return INF;

	if (day >= N - 1)
		return dirty * stNum[day];

	int &ret = cache[day][leftM][dirty];
	if (ret != -1)
		return ret;

	int clean = min_unplea(day + 1, leftM - 1, 0);
	int unclean = min_unplea(day + 1, leftM, dirty + stNum[day]);

	return ret = min(
		clean + dirty * stNum[day],
		unclean + dirty * stNum[day]
	);
}

vector<int> reconstruct(int day, int leftM, int dirty) {

	if (day >= N - 1)
		return vector<int>();

	int clean = min_unplea(day + 1, leftM - 1, 0);
	int unclean = min_unplea(day + 1, leftM, dirty + stNum[day]);

	if (min_unplea(day, leftM, dirty) ==
		clean + dirty * stNum[day])
	{
		vector<int> ret;
		vector<int> nxt = reconstruct(day + 1, leftM - 1, 0);

		ret.push_back(day);
		ret.insert(ret.end(), nxt.begin(), nxt.end());

		return ret;
	}

	return reconstruct(day + 1, leftM, stNum[day] + dirty);
}

void data_in() {

	int M;

	freopen("input.txt", "r", stdin);
	memset(cache, -1, sizeof(int) * 100 * 100 * 2000);
	scanf("%d %d ", &N, &M);

	stNum = vector<int>(N);

	for (int i = 0; i < N; i++) {
		scanf("%d ", &stNum[i]);
	}

	printf("%d\n",min_unplea(0, M, 0));
	vector<int> path = reconstruct(0, M, 0);
	for (int i = 0; i < path.size(); i++) {
		printf("%d ", path[i] + 1);
	}

}

int main() {
	data_in();
}
