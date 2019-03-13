#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N, L, R;
int town[50][50];
bool visit[50][50];

bool is_move(int y, int x) {

	visit[y][x] = true;

	int sum = town[y][x];
	vector<pair<int, int>> ret;
	queue<pair<int, int>> q;
	
	ret.push_back(make_pair(y, x));
	q.push(make_pair(y, x));

	while (!q.empty()) {

		pair<int, int> here = q.front(); q.pop();

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (abs(i + j) == 1) {
					int this_y = here.first + i, this_x = here.second + j;
					
					if (!(this_y < 0 || this_y >= N || this_x < 0 || this_x >= N)) {
						if (!visit[this_y][this_x]) {
							
							if (abs(town[here.first][here.second] - town[this_y][this_x]) >= L &&
								abs(town[here.first][here.second] - town[this_y][this_x]) <= R)
							{
								visit[this_y][this_x] = true;

								sum += town[this_y][this_x];
								ret.push_back(make_pair(this_y, this_x));
								q.push(make_pair(this_y, this_x));
							}
						}
					}
				}
			}
		}
	}

	if (ret.size() > 1) {
		int value = sum / ret.size();

		for (int i = 0; i < ret.size(); i++)
			town[ret[i].first][ret[i].second] = value;

		return true;
	}

	return false;

}

void initialize_visit() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = false;

}

int move_cnt() {

	initialize_visit();
	bool move;
	int ret = -1;

	do {
		move = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(!visit[i][j])
					move |= is_move(i, j);
			}
		}

		ret++;
		initialize_visit();
	} while (move);
	
	return ret;
}

void data_in() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d ", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d ", &town[i][j]);
	}

	printf("%d ", move_cnt());

}

int main() {

	data_in();

}
