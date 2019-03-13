#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 11, MAX_H = 31;
int N, M, H;
int ladder[MAX_H][MAX_N];

bool is_success() {

	for (int i = 1; i <= N; i++) {
		int x = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][x])
				x = ladder[j][x];
		}
		if (x != i)
			return false;
	}

	return true;
}

bool lay_ladder(int y, int x, int cnt) {

	if (cnt == 0)
		return is_success();

	for(int i = y; i <= H; i++)
		for (int j = 1; j <= N; j++) {
			if (i == y && j == 1)
				j = x + 1;

			if (!ladder[i][j] && !ladder[i][j + 1]) {
				ladder[i][j] = j + 1;
				ladder[i][j + 1] = j;
				
				if (lay_ladder(i, j, cnt - 1))
					return true;

				ladder[i][j] = 0;
				ladder[i][j + 1] = 0;

			}
		}

	return false;
}

void data_in() {

	scanf("%d %d %d ", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d ", &a, &b);

		ladder[a][b] = b + 1;
		ladder[a][b + 1] = b;
	}

	int cnt = 0;
	for (; cnt < 4; cnt++) {
		if (lay_ladder(1, 0, cnt)) {
			printf("%d ", cnt);
			break;
		}
	}

	if(cnt == 4)
		printf("-1");
	
}

int main() {

	data_in();

}
