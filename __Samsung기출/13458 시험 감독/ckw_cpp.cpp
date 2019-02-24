#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int find_max_block(vector<vector<int>>&board) {

	int max_val = 0;

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board.size(); j++) {
			max_val = max(max_val, board[i][j]);
		}

	return max_val;
}

vector<vector<int>> rotate_block(vector<vector<int>>&board) {

	vector<vector<int>> ret = vector<vector<int>>(board.size(), vector<int>(board.size(), 0));

	for (int i = board.size() - 1, k = 0; i >= 0; i--, k++) {
		for (int j = 0; j < board.size(); j++) {
			ret[k][j] = board[j][i];
		}
	}

	return ret;
}

vector<vector<int>> sum_board(vector<vector<int>> &board) {

	vector<vector<int>> ret = vector<vector<int>>(board.size(), vector<int>(board.size(), 0));

	for (int i = 0; i < board.size(); i++) {
		int prev = 0, prev_j = 0, prev_i = i;
		for (int j = 0; j < board.size(); j++) {
			if (prev == board[j][i]) {
				ret[prev_j][prev_i] = 0;
				ret[j][i] = prev * 2;
				prev = 0;
			}

			else if (board[j][i]) {
				prev = board[j][i];
				prev_j = j;
				prev_i = i;
				ret[j][i] = board[j][i];
			}
		}

		int cnt = 0;
		for (int j = 0; j < board.size(); j++)
			if (ret[j][i]) {
				ret[cnt][i] = ret[j][i];
				if (cnt++ != j)
					ret[j][i] = 0;
			}

	}

	return ret;
}

int max_block(vector<vector<int>> &board, int cnt) {

	if (cnt == 5)
		return find_max_block(board);

	int ret = -1;

	for (int i = 0; i < 4; i++) {
		board = rotate_block(board);

		vector<vector<int>> sum_bd = sum_board(board);
		ret = max(ret, max_block(sum_bd, cnt + 1));
	}

	return ret;
}

void data_in() {
	int N;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &N);
	vector<vector<int>> blocks;
	blocks = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d ", &blocks[i][j]);
		}

	printf("%d ", max_block(blocks, 0));
}

int main() {

	data_in();

}