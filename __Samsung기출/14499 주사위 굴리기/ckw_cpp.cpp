#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int N, M;

struct Dice {

	int x, y;
	int values[6];
	int shape[6];

	Dice(int _x, int _y) {
		x = _x;
		y = _y;

		for (int i = 0; i < 6; i++) {
			values[i] = 0;
			shape[i] = i;
		}
	};

	void make_model(int model[3][4], int dir) {

		model[0][1] = shape[1];
		model[1][0] = shape[3];
		model[1][1] = shape[0];
		model[1][2] = shape[2];
		model[2][1] = shape[4];
		model[3][1] = shape[5];
		
		if (dir == 1) {
			int tmp = model[1][2];
			model[1][2] = model[1][1];
			model[1][1] = model[1][0];
			model[1][0] = model[3][1];
			model[3][1] = tmp;
		}

		if (dir == 2) {
			int tmp = model[1][0];
			model[1][0] = model[1][1];
			model[1][1] = model[1][2];
			model[1][2] = model[3][1];
			model[3][1] = tmp;
		}

		if (dir == 3)
		{
			int tmp = model[0][1];

			for (int i = 0; i < 3; i++) {
				model[i][1] = model[i + 1][1];
			}

			model[3][1] = tmp;
		}

		if (dir == 4) {
			int tmp = model[3][1];

			for (int i = 3; i > 0; i--) {
				model[i][1] = model[i - 1][1];
			}

			model[0][1] = tmp;
		}

	}

	//주사위를 굴려서 다음 shape로 변경시킨다.
	void roll_dice(int dir) {
		int dice_model[3][4];
		
		make_model(dice_model, dir);

		shape[0] = dice_model[1][1];
		shape[1] = dice_model[0][1];
		shape[2] = dice_model[1][2];
		shape[3] = dice_model[1][0];
		shape[4] = dice_model[2][1];
		shape[5] = dice_model[3][1];
	}

	int roll(vector<vector<int>> &map, int dir) {

		pair<int, int> dir_pair = get_dir(dir);
		pair<int, int> nxt = make_pair(dir_pair.first + y, dir_pair.second + x);

		if (nxt.first < N && nxt.first >= 0 && nxt.second < M && nxt.second >= 0) {

			y = nxt.first;  x = nxt.second;
			roll_dice(dir);

			if (!map[y][x])
				map[y][x] = values[shape[5]];
			else {
				values[shape[5]] = map[y][x];
				map[y][x] = 0;
			}

			return values[shape[0]];
		}

		return -1;
	}

	pair<int, int> get_dir(int dir) {
		switch (dir)
		{
		case 1: return make_pair(0, 1);
		case 2: return make_pair(0, -1);
		case 3: return make_pair(-1, 0);
		case 4: return make_pair(1, 0);
		}
	}

};

void data_in() {

	int y, x;
	int K;

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d %d ", &N, &M, &y, &x, &K);

	map = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int value;
			scanf("%d ", &value);
			map[i][j] = value;
		}
	}

	Dice d(x, y);

	for (int i = 0; i < K; i++) {
		int dir;

		scanf("%d ", &dir);

		int result = d.roll(map, dir);

		if (result != -1)
			printf("%d\n", result);
	}
}

int main() {
	data_in();
}