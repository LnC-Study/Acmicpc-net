#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
//2는 사과, 0은 암것도 없는 것, 1은 몸
vector<string> board;

struct Snake {
	pair<int, int> head;
	pair<int, int> tail;
	pair<int, int> head_dir;
	pair<int, int> tail_dir;
	queue<pair<pair<int, int>, char>> corners;

	Snake() {
		head = make_pair(1, 1);
		tail = make_pair(1, 1);
		head_dir = make_pair(0, 1);
		tail_dir = make_pair(0, 1);

	}

	//0은 그냥 지나 가게 될 경우
	//1은 사과를 먹은 경우
	//-1은 벽에 부딪힌 경우 혹은 몸에 부딪힌 경우
	int head_go(vector<string> &board) {
		int nxtY = head.first + head_dir.first;
		int nxtX = head.second + head_dir.second;

		if (nxtX < 1 || nxtX > N || 
			nxtY < 1 || nxtY > N ||
			board[nxtY][nxtX] == '1') {
			return -1;
		}

		head = make_pair(nxtY, nxtX);


		if (board[nxtY][nxtX] == '2') {
			board[nxtY][nxtX] = '1';
			return 1;
		}

		board[nxtY][nxtX] = '1';
		return 0;
	}

	//꼬리를 지우고, 꼬리가 코너에 있다면, 꼬리의 방향을 바꿔준다.
	void tail_erase() {
		int nxtY = tail.first + tail_dir.first;
		int nxtX = tail.second + tail_dir.second;

		if(corners.size() > 0)
			if (make_pair(nxtY, nxtX) == corners.front().first) {
				dir_change(tail_dir, corners.front().second);
				corners.pop();
			}

		board[tail.first][tail.second] = '0';
		tail = make_pair(nxtY, nxtX);
	}

	void dir_change(pair<int,int>& dir, char c) {
		if (dir == make_pair(1, 0))
			dir = (c == 'D' ? make_pair(0, -1) : make_pair(0, 1));
		else if (dir == make_pair(-1, 0))
			dir = (c == 'D' ? make_pair(0, 1) : make_pair(0, -1));
		else if (dir == make_pair(0, 1))
			dir = (c == 'D' ? make_pair(1, 0) : make_pair(-1, 0));
		else if (dir == make_pair(0, -1))
			dir = (c == 'D' ? make_pair(-1, 0) : make_pair(1, 0));
	}

	void head_dir_change(char c) {
		corners.push(make_pair(head, c));
		dir_change(head_dir, c);
	}
};

queue<pair<int, char>> dir_change;

int game_finish_time() {

	int cnt = 0;

	Snake sn;

	int state = sn.head_go(board);
	while (state != -1) {
		cnt++;
		
		if(dir_change.size() > 0)
			if (cnt == dir_change.front().first) {
				sn.head_dir_change(dir_change.front().second);
				dir_change.pop();
			}

		if (!state)
			sn.tail_erase();

		state = sn.head_go(board);
	}

	return cnt;
}

void data_in() {

	int K,L;

	scanf("%d ", &N);
	scanf("%d ", &K);

	board = vector<string>(N+1, string(N+1, '0'));

	for (int i = 0; i < K; i++) {

		int aX, aY;

		scanf("%d %d ", &aY, &aX);
		board[aY][aX] = '2';
	}

	scanf("%d ", &L);
	for (int i = 0; i < L; i++) {
		int x, c;
		scanf("%d %c ", &x, &c);
		dir_change.push(make_pair(x, c));
	}

	printf("%d ", game_finish_time() + 1);

}

int main() {

	data_in();

}
