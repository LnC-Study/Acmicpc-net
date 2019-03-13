#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
int shark_size;
int left_feed;
int board[20][20];

pair<int, int> pos;


pair<int, int> next_pos(int& time) {

	int least_y = 21;
	int least_x = 21;
	int ret_cost = 0;
	bool visit[20][20] = { false };

	pair<int, int> ret = make_pair(-1,-1);
	map<pair<int, int>, int> cost;
	queue<pair<int, int>> q;
	
	q.push(pos);
	cost[pos] = 0;
	
	while (!q.empty()) {
		bool stop = false;
		pair<int, int> here = q.front(); q.pop();

		
		for(int i = -1 ; i <= 1 && !stop; i++)
			for (int j = -1; j <= 1 && !stop; j++) {
				//상하좌우만 볼거다
				if (abs(i + j) == 1) {
					int y = here.first + i, x = here.second + j;

					//범위안에 있고, 방문한 적이 있는지?
					if (!(y < 0 || y >= N || x < 0 || x >= N) && !visit[y][x] && pos != make_pair(y,x)) {
						visit[y][x] = true;

						//먹을 수 있는 애야?
						if (board[y][x] < shark_size && board[y][x]) {
							if (ret.first == -1 || ret_cost == cost[here] + 1) {
								//맨 위에 있는애야?
								if (y < least_y) {
									ret = make_pair(y, x);
									least_y = y;
									least_x = x;
								}
								//맨 왼쪽에 있는 애야?
								else if (y == least_y) {
									if (x < least_x) {
										ret = make_pair(y, x);
										least_x = x;
									}
								}

								ret_cost = cost[here] + 1;
							}// 더 멀리 있는애는 볼 필요가 없다.
							else {
								stop = true;
							}
						}
						// 다음칸으로 넘어가자
						else if (board[y][x] <= shark_size) {
							cost[make_pair(y, x)] = cost[here] + 1;
							q.push(make_pair(y, x));
						}
					}
				}
			}

	}

	time = ret_cost;
	//리턴값이 있어?
	if (ret.first != -1) {
		board[pos.first][pos.second] = 0;
		board[ret.first][ret.second] = 9;
		return ret;
	}

	return make_pair(-1, -1);
}

int max_time_without_mom() {

	int total_time = 0;
	int time = 0;

	pos = next_pos(time);

	while (pos.first != -1)
	{
		total_time += time;

		left_feed--;

		if (left_feed == 0) {
			shark_size++;
			left_feed = shark_size;
		}

		pos = next_pos(time);
	}

	return total_time;

}

void data_in() {

	scanf("%d ", &N);

	for(int i = 0 ; i < N ; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d ", &board[i][j]); 

			if (board[i][j] == 9) {
				pos = make_pair(i, j);
			}
		}

	shark_size = 2;
	left_feed = 2;

	printf("%d ", max_time_without_mom());

}

int main() {

	data_in();

}
