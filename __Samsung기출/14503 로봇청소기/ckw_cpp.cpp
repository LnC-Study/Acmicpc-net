#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 50;
int N, M;
pair<int, int>pos;
int dir;
int board[MAX_N][MAX_N];
bool is_cleaned[MAX_N][MAX_N];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int next_dir(int dir) {

	if (dir != 0)
		return --dir;

	return 3;

}

pair<int, int> back_pos(int dir, pair<int, int> pos) {
	pair<int, int> ret = pos;
	
	ret.first += -1 * dy[dir];
	ret.second += -1 * dx[dir];

	return ret;
}

int clean_area() {

	int cnt = 1;
	is_cleaned[pos.first][pos.second] = true;
	
	while (true) {
		int i;
		for (i = 0; i < 4; i++) {
			dir = next_dir(dir);

			int y = pos.first + dy[dir], x = pos.second + dx[dir];

			if(!(y < 0 || y >= N || x < 0 || x >= M))
				if (!board[y][x] && !is_cleaned[y][x]) {
					pos = make_pair(y, x);
					is_cleaned[y][x] = true;
					cnt++;
					break;
				}
		}

		if (i == 4) {
			pos = back_pos(dir, pos);

			if (board[pos.first][pos.second])
				break;
		}

	}

	return cnt;

}

void data_in() {

	scanf("%d %d ", &N, &M);

	scanf("%d %d %d ", &pos.first, &pos.second, &dir);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d ", &board[i][j]);

	printf("%d ", clean_area());

}

int main() {

	data_in();
}
