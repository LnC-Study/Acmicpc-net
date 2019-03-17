#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 2e9;
const int MAX_N = 20;
int board[MAX_N][MAX_N];
int N;
int min_diff() {

	vector<bool> choose = vector<bool>(N, false);

	for (int i = 0; i < N / 2; i++)
		choose[i] = true;

	int min_val = INF;

	do {
		int team1 = 0, team2 = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (choose[i] == choose[j]) {
					if (choose[i])
						team1 += board[i][j];
					else
						team2 += board[i][j];
				}
			}
		}

		min_val = min(min_val, abs(team1 - team2));

	} while (prev_permutation(choose.begin(), choose.end()));

	return min_val;
}

void data_in() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d ", &board[i][j]);

	printf("%d ", min_diff());

}

int main() {

	data_in();
}