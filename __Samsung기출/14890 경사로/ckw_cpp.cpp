#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;
int board[MAX_N][MAX_N];
int N, L;

bool is_avail_path(vector<int> path) {

	int prev_same_length = 0;
	int prev = -1;

	for (int i = 0; i < path.size(); i++) {

		if (prev == -1 || prev == path[i])
			prev_same_length++;

		else if (prev + 1 == path[i]) {
			if (prev_same_length < L)
				return false;

			prev_same_length = 1;
		}

		else if (prev - 1 == path[i]) {
			int nxt_same_length = 0;
			bool have_to_sub = true;

			prev_same_length = 0;

			for (; nxt_same_length < L && path[i] == prev - 1; i++, nxt_same_length++)
				if (i >= path.size() - 1) { 
					have_to_sub = false; 
					nxt_same_length++; 
					break; 
				}
			
			if(have_to_sub)
				i--;

			if (nxt_same_length < L)
				return false;
		}

		else
			return false;

		prev = path[i];
	}

	return true;
}

int max_path() {

	int ret = 0;

	vector<int> tmp1, tmp2;
	for (int i = 0; i < N; i++) {
		tmp1.clear(), tmp2.clear();

		for (int j = 0; j < N; j++) {
			tmp1.push_back(board[i][j]);
			tmp2.push_back(board[j][i]);
		}

		if (is_avail_path(tmp1))
			ret++;
		if (is_avail_path(tmp2))
			ret++;
	}

	return ret;
}

void data_in() {

	scanf("%d %d ", &N, &L);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d ", &board[i][j]);

	printf("%d ", max_path());
}

int main() {

	data_in();

}