#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> hole;

bool visit[10][10][10][10];

//R이 들어가서 성공하면 1, B가 들어간 경우 -1, 둘다 아닌경우 0, 움직이지 않는경우 2
int rotate(vector<string>& graph, pair<int, int>&R, pair<int, int>&B, int dir) {
	int ret = 0, delta = 1, cnt = 0;
	pair<int, int> tmpR = R, tmpB = B;

	while (graph[tmpR.first + dy[dir]][tmpR.second + dx[dir]] != '#')
	{
		tmpR.first += dy[dir];
		tmpR.second += dx[dir];
		cnt++;
		if (graph[tmpR.first][tmpR.second] == 'O')
			ret = 1;
	}

	while (graph[tmpB.first + dy[dir]][tmpB.second + dx[dir]] != '#')
	{
		tmpB.first += dy[dir];
		tmpB.second += dx[dir];
		cnt++;
		if (graph[tmpB.first][tmpB.second] == 'O')
			ret = -1;
	}

	if (tmpR == tmpB) {
		switch (dir) {
		case 0:	R.first > B.first ? tmpB.first-- : tmpR.first--; cnt--; break;
		case 1: R.first > B.first ? tmpR.first++ : tmpB.first++; cnt--; break;
		case 2:	R.second > B.second ? tmpB.second-- : tmpR.second--;  cnt--; break;
		case 3:	R.second > B.second ? tmpR.second++ : tmpB.second++;  cnt--; break;
		}
	}

	graph[R.first][R.second] = '.';
	graph[B.first][B.second] = '.';
	graph[tmpR.first][tmpR.second] = 'R';
	graph[tmpB.first][tmpB.second] = 'B';

	R = tmpR;
	B = tmpB;

	if (cnt == 0)
		ret = 2;

	return ret;
}

void revert(vector<string>& graph, pair<int, int>&R, pair<int, int>&B, pair<int, int>tmpR, pair<int, int>tmpB) {
	graph[R.first][R.second] = '.';
	graph[B.first][B.second] = '.';
	graph[tmpR.first][tmpR.second] = 'R';
	graph[tmpB.first][tmpB.second] = 'B';
	graph[hole.first][hole.second] = 'O';
	R = tmpR;
	B = tmpB;
}

int min_rotate(int cnt, vector<string>& graph, pair<int, int>&R, pair<int, int>&B) {

	int ret = INF;

	if (cnt > 10)
		return INF;

	pair<int, int> tmpR = R, tmpB = B;

	for (int i = 0; i < 4; i++) {

		int tmp = rotate(graph, R, B, i);

		if (!tmp) {
			ret = min(ret, min_rotate(cnt + 1, graph, R, B));
		}
		else if (tmp == 1)
			ret = min(ret, cnt);

		else if (tmp == -1)
			ret = min(ret, INF);

		if (tmp != 2)
			revert(graph, R, B, tmpR, tmpB);
	}

	return ret;
}

void data_in() {

	int N, M;
	pair<int, int> R, B;
	vector<string> graph;

	scanf("%d %d ", &N, &M);

	graph = vector<string>(N, string(M, '.'));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c ", &graph[i][j]);

			if (graph[i][j] == 'R')
				R = make_pair(i, j);

			if (graph[i][j] == 'B')
				B = make_pair(i, j);

			if (graph[i][j] == 'O')
				hole = make_pair(i, j);
		}
	}

	int result = min_rotate(1, graph, R, B);
	printf("%d ", result == INF ? -1 : result);
}

int main() {

	data_in();

}