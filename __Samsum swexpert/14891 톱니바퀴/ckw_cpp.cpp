#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

char gear[4][8];
vector<bool> is_rotated;

void rotate_gear(int num, int dir) {

	if (is_rotated[num])
		return;

	is_rotated[num] = true;

	char tmp;

	if (num > 0)
		if (gear[num][6] != gear[num - 1][2])
			rotate_gear(num - 1, dir * -1);

	if (num < 3)
		if (gear[num][2] != gear[num + 1][6])
			rotate_gear(num + 1, dir * -1);

	//rotate
	if (dir == 1) {
		tmp = gear[num][7];
		for (int i = 7; i >= 1; i--) gear[num][i] = gear[num][i - 1];
		gear[num][0] = tmp;
	}
	else {
		tmp = gear[num][0];
		for (int i = 0; i < 7; i++) gear[num][i] = gear[num][i + 1];
		gear[num][7] = tmp;
	}
}

int score_sum() {

	int ret = 0;

	for (int i = 0; i < 4; i++)
		if (gear[i][0] != '0')
			ret += pow(2, i);

	return ret;
}

void data_in() {

	for(int i = 0 ; i < 4; i++)
		for (int j = 0; j < 8; j++) {
			scanf("%c ", &gear[i][j]);
		}

	int K;

	scanf("%d ", &K);

	for (int i = 0; i < K; i++) {
		int num, rotate_direction;

		is_rotated = vector<bool>(4, false);

		scanf("%d %d ", &num, &rotate_direction);

		rotate_gear(--num, rotate_direction);
	}

	printf("%d ", score_sum());

}

int main() {

	data_in();

}
