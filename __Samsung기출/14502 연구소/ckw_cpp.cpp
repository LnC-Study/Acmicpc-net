#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAX_N = 8;
const int INF = 987654321;
vector<pair<int, int>> infection;
bool visit[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int N,M;

int max_safe_area() {

	int ret = 0;
	vector<pair<int, int>> changed_area;
	queue<pair<int, int>> q;

	
	for (int i = 0; i < infection.size(); i++) {

		q.push(infection[i]);

		while (!q.empty()) {
			pair<int, int> here = q.front(); q.pop();

			for(int dy = -1 ; dy <= 1; dy++)
				for (int dx = -1; dx <= 1; dx++) {
					if (abs(dx + dy) == 1) {
						int y = here.first + dy, x = here.second + dx;

						if(!(y < 0 || y >= N || x < 0 || x >= M))
							if (!board[y][x]) {
								board[y][x] = 2;
								changed_area.push_back(make_pair(y, x));
								q.push(make_pair(y, x));
							}

					}
				}
		}
	}

	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!board[i][j])
				ret++;
		}

	for (int i = 0; i < changed_area.size(); i++)
		board[changed_area[i].first][changed_area[i].second] = 0;

	return ret;
}

int get_max_area() {
	
	int ret = 0;

	vector<pair<int, int>> zeros;

	for(int i = 0 ; i < N ;i++)
		for (int j = 0; j < M; j++) {
			if (!board[i][j])
				zeros.push_back(make_pair(i, j));
		}

	for (int i = 0; i < zeros.size(); i++) {
		board[zeros[i].first][zeros[i].second] = 1;
		for (int j = i + 1; j < zeros.size(); j++) {
			board[zeros[j].first][zeros[j].second] = 1;
			for (int k = j + 1; k < zeros.size(); k++) {
				board[zeros[k].first][zeros[k].second] = 1;
				ret = max(ret, max_safe_area());
				board[zeros[k].first][zeros[k].second] = 0;
			}
			board[zeros[j].first][zeros[j].second] = 0;
		}
		board[zeros[i].first][zeros[i].second] = 0;
	}

	return ret;

}

void data_in() {

	scanf("%d %d ", &N, &M);

	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d ", &board[i][j]);
			
			if (board[i][j] == 2)
				infection.push_back(make_pair(i, j));
		}

	printf("%d ", get_max_area());

}

int main() {

	data_in();
}
