#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[20][20][60];
int map[20][20];
int N, M;

int max_town(int y, int x, int k) {

	if (k == 0)
		return cache[y][x][k] = map[y][x];

	int dir = 0;
	int &ret = cache[y][x][k];
	ret = cache[y][x][k - 1];

	for (int j = x, i = y - k ; dir != 4 ;) {
		if (!(i < 0 || i > N - 1 || j < 0 || j > N - 1))
			ret += map[i][j];

		switch (dir)
		{
		case 0:	i++; j--; if (i == y) dir++; break;
		case 1: i++; j++; if (j == x) dir++; break;
		case 2: i--; j++; if (i == y) dir++; break;
		case 3: i--; j--; if (j == x) dir++; break;
		}
	}

	return ret;
}

int build_cost(int K) {
	return K * K + (K - 1)*(K - 1);
}

int resonable_max_town() {

	int ret = 0;

	for (int k = 0; k < N * 3; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				int towns = max_town(i, j, k);
				
				if (towns * M > build_cost(k + 1))
					ret = max(ret, towns);
			}
		}
	}

	return ret;
}


void data_in() {

	int T;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		memset(cache, 0, sizeof(cache));
		memset(map, 0, sizeof(map));

		scanf("%d %d ", &N, &M);

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d ", &map[j][k]);
			}
		}

		printf("#%d %d\n", i + 1, resonable_max_town());
	}
}


int main() {

	data_in();

}