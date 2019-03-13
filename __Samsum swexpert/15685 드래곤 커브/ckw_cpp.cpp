#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 101;
int N;
bool board[SIZE][SIZE];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void draw_curve(int x,int y, int d, int g) {

	vector<int> dirs;

	dirs.push_back(d);

	for (int i = 0; i < g; i++) {
		for (int j = dirs.size() - 1; j >= 0; j--) {
			dirs.push_back((dirs[j] + 1) % 4);
		}
	}

	board[y][x] = true;
	for (int i = 0; i < dirs.size(); i++) {
		y += dy[dirs[i]];
		x += dx[dirs[i]];

		if (y < 0 || y >= SIZE || x < 0 || x >= SIZE )
			continue;

		board[y][x] = true;
	}

}

int dragon_curve_cnt() {

	int cnt = 0;

	for(int i = 0 ; i < SIZE - 1; i++)
		for (int j = 0; j < SIZE - 1; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				cnt++;
		}

	return cnt;

}

void data_in() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d ", &x, &y, &d, &g);
		draw_curve(x, y, d, g);
	}

	printf("%d ", dragon_curve_cnt());
}

int main() {

	data_in();
}
