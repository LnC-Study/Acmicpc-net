#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#define MAX 800000001
#define NEGCOORD -10001

using namespace std;

int T;
priority_queue<pair<int, int>> x_base_coord;
priority_queue<pair<int, int>> y_base_coord;

int calc_dist(pair<int, int> a, pair<int, int> b) {

	int c = pow(a.first - b.first, 2);
	int d = pow(a.second - b.second, 2);

	return c + d;
}

int min_dist() {

	int ret = MAX;

	pair<int, int> prev_x = make_pair(NEGCOORD, NEGCOORD);
	pair<int, int> prev_y = make_pair(NEGCOORD, NEGCOORD);

	for (int i = 0; i < T; i++) {
		if (prev_x.first == NEGCOORD) {
			prev_x = x_base_coord.top();
			prev_y = y_base_coord.top();
			x_base_coord.pop();
			y_base_coord.pop();
			continue;
		}

		pair<int, int> tmp_x = x_base_coord.top();
		pair<int, int> tmp_y = y_base_coord.top();

		x_base_coord.pop();
		y_base_coord.pop();

		int x_dist = calc_dist(prev_x, tmp_x);
		int y_dist = calc_dist(prev_y, tmp_y);

		ret = min(ret, x_dist);
		ret = min(ret, y_dist);

		prev_x = tmp_x;
		prev_y = tmp_y;
	}

	return ret;
}

void data_in() {
	
	scanf("%d ", &T);

	for (int i = 0; i < T; i++) {
		int first, second;
		scanf("%d %d ", &first, &second);

		x_base_coord.push(make_pair(first, second));
		y_base_coord.push(make_pair(second, first));
	}

	printf("%d", min_dist());

}

int main() {

	data_in();

}
