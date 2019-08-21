#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 8;
int N, M;
int board[MAX_N][MAX_N];
vector<pair<int, int>>walls;

struct CCTV {
	pair<int, int> pos;
	int type;
	vector<int> dirs;

	CCTV() {}
	CCTV(int y, int x, int _type){
		pos = make_pair(y, x);
		type = _type;
		dir_init();
	}

	void dir_init() {
		switch (type)
		{
		case 1: dirs.push_back(2); break;
		case 2: dirs.push_back(2); dirs.push_back(4); break;
		case 3: dirs.push_back(2); dirs.push_back(1); break;
		case 4: dirs.push_back(2); dirs.push_back(1); dirs.push_back(4); break;
		case 5: dirs.push_back(2); dirs.push_back(1); dirs.push_back(3); dirs.push_back(4); break;
		}
	}

	bool has_next() {
		return dirs[0] != 2;
	}

	void next_rotate() {

		switch (type)
		{
		case 4:
			if (dirs[2] == 4) dirs[2] = 1;
			else dirs[2] = dirs[2] + 1;
		case 3:
			if (dirs[1] == 4) dirs[1] = 1;
			else dirs[1] = dirs[1] + 1;
		case 1: 
			if (dirs[0] == 4) dirs[0] = 1;
			else dirs[0] = dirs[0] + 1;
			break;
		case 2:
			if (dirs[0] == 2) { dirs[0] = 1; dirs[1] = 3; }
			else { dirs[0] = 2; dirs[1] = 4; }
			break;
		}
	}
};

vector<CCTV> cctvs;

vector<pair<int,int>> make_sharp(pair<int,int>pos, int dir) {

	int y = pos.first;
	int x = pos.second;

	vector<pair<int, int>>ret;

	if (dir == 1) {
		for (int i = y - 1; i >= 0; i--)
			if (board[i][x] == 6)
				break;
			else if (!board[i][x]) {
				board[i][x] = 7;
				ret.push_back(make_pair(i, x));
			}
	}

	else if (dir == 2) {
		for (int j = x + 1; j < M; j++)
			if (board[y][j] == 6)
				break;
			else if (!board[y][j]) {
				board[y][j] = 7;
				ret.push_back(make_pair(y, j));
			}
	}

	else if (dir == 3) {
		for (int i = y + 1; i < N; i++)
			if (board[i][x] == 6)
				break;
			else if (!board[i][x]) {
				board[i][x] = 7;
				ret.push_back(make_pair(i, x));
			}
	}

	else if (dir == 4) {
		for(int j = x - 1; j >= 0 ; j--)
			if (board[y][j] == 6)
				break;
			else if (!board[y][j]) {
				board[y][j] = 7;
				ret.push_back(make_pair(y, j));
			}
	}
	
	return ret;
}

int find_min_area() {

	int ret = 0;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!board[i][j])
				ret++;
		}

	return ret;
}

int min_rectangle_area(int idx) {

	if (idx == cctvs.size())
		return find_min_area();

	int ret = INF;
	CCTV& here = cctvs[idx];

	do{
		vector<pair<int, int>> revert;

		for (int i = 0; i < here.dirs.size(); i++) {
			vector<pair<int, int>> tmp = make_sharp(here.pos, here.dirs[i]);
			revert.insert(revert.end(), tmp.begin(), tmp.end());
		}

		ret = min(ret, min_rectangle_area(idx + 1));

		for (int j = 0; j < revert.size(); j++) {
			board[revert[j].first][revert[j].second] = 0;
		}

		revert.clear();
		
		here.next_rotate();
	} while (here.has_next());

	return ret;
}

void data_in() {

	scanf("%d %d ", &N, &M);

	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d ", &board[i][j]);

			if (board[i][j])
			{
				if (board[i][j] == 6)
					walls.push_back(make_pair(i, j));
				else
					cctvs.push_back(CCTV(i, j, board[i][j]));
			}
		}

	printf("%d ", min_rectangle_area(0));
}

int main() {

	data_in();

}
