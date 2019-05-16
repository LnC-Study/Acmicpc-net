#include <string>
#include <vector>

using namespace std;

pair<int, int> pos[10];

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = a.first*b.second + b.first*c.second + c.first*a.second;
	op -= (a.second*b.first + b.second*c.first + c.second*a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
	pair<int, int> a = x.first;
	pair<int, int> b = x.second;
	pair<int, int> c = y.first;
	pair<int, int> d = y.second;
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

void make_pos() {

	pos[1] = make_pair(2, 0);
	pos[2] = make_pair(2, 1);
	pos[3] = make_pair(2, 2);
	pos[4] = make_pair(1, 0);
	pos[5] = make_pair(1, 1);
	pos[6] = make_pair(1, 2);
	pos[7] = make_pair(0, 0);
	pos[8] = make_pair(0, 1);
	pos[9] = make_pair(0, 2);

}

vector<pair<pair<int, int>, pair<int, int>>> make_lines(vector<int> pattern) {

	vector<pair<pair<int, int>, pair<int, int>>> ret;

	for (int i = 0; i < pattern.size() - 1; i++) {
		ret.push_back(make_pair(pos[pattern[i]], pos[pattern[i + 1]]));
	}

	return ret;
}

vector<int> solution(vector<int> pattern) {

	vector<int> answer;

	make_pos();
	vector<pair<pair<int, int>, pair<int, int>>> lines = make_lines(pattern);

	answer = vector<int>(lines.size());

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines.size(); j++) {

			if (i != j) {
				answer[i] += isIntersect(lines[i], lines[j]);
			}
		}
	}
	

	return answer;
}
