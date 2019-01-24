#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>
#define INF 987654321
using namespace std;

vector<int> aquarium;
vector<int> hole;

//구멍의 개수
int number_of_holes(int left, int right);
//가장 얕은 곳
pair<long long,pair<int,int>> find_lowest(int left, int right);
//사각형의 크기
long long rectangle(int left, int right);

pair<long long, double> aqua2(long long left, long long right, long long height) {

	long long hole_nums = (long long)number_of_holes(left, right);

	if (hole_nums == 0)
		return make_pair(rectangle(left, right) - ((right - left + 1) * height), 0);

	pair<long long, pair<int, int>> lowest = find_lowest(left, right);

	double time = (double)((right - left + 1) * (lowest.first - height)) / (double)hole_nums;

	pair<long long, double> l_side = aqua2(left, lowest.second.first - 1, lowest.first);
	pair<long long, double> r_side = aqua2(lowest.second.second + 1, right, lowest.first);

	return make_pair(l_side.first + r_side.first, l_side.second + r_side.second + time);

}

int number_of_holes(int left, int right) {
	int cnt = 0;
	for (int i = left; i <= right; i++) {
		if (hole[i])
			cnt++;
	}

	return cnt;
}

pair<long long, pair<int, int>> find_lowest(int left, int right) {

	long long ret = INF;
	int start, end;
	bool continuous = false;

	for (int i = left; i <= right; i++) {
		if (aquarium[i] < ret) {
			start = i;
			end = i;
			ret = (long long)aquarium[i];
			continuous = true;
		}

		else if (aquarium[i] == ret && continuous) {
			end = i;
		}

		else
			continuous = false;

	}

	return make_pair(ret, make_pair(start, end));
}

long long rectangle(int left, int right) {
	long long ret = 0;

	for (int i = left; i <= right; i++) {
		ret += aquarium[i];
	}

	return ret;
}


void data_in() {

	freopen("input.txt", "r", stdin);

	int N, k;

	scanf("%d ", &N);

	int prevX = 0;

	for (int i = 0; i < N / 2; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = prevX + 1; j < x1; j++) {
			aquarium.push_back(aquarium[prevX]);
		}

		aquarium.push_back(y2);
		prevX = x2;
	}

	scanf("%d", &k);
	hole = vector<int>(aquarium.size());

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		hole[x1] = y1;
	}

	pair<long long, double> result = aqua2(0, prevX - 1, 0);

	printf("%.2lf\n%lli", result.second, result.first);

}

int main() {

	data_in();

}
