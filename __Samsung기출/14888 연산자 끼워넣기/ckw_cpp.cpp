#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;
const int MAX_N = 11;
int N;
int nums[MAX_N];
int operators[4];

int get_min(int idx) {

	if (idx == 0)
		return nums[idx];

	int min_val = INF;

	for (int i = 0; i < 4; i++) {
		if (operators[i]) {
			operators[i]--;
			switch (i) {
			case 0:
				min_val = min(min_val, get_min(idx - 1) + nums[idx]); break;
			case 1:
				min_val = min(min_val, get_min(idx - 1) - nums[idx]); break;
			case 2:
				min_val = min(min_val, get_min(idx - 1) * nums[idx]); break;
			case 3:
				min_val = min(min_val, get_min(idx - 1) / nums[idx]); break;
			}
			operators[i]++;
		}
	}

	return min_val;
}

int get_max(int idx) {

	if (idx == 0)
		return nums[idx];

	int max_val = -INF;

	for (int i = 0; i < 4; i++) {
		if (operators[i]) {
			operators[i]--;
			switch (i) {
			case 0:
				max_val = max(max_val, get_max(idx - 1) + nums[idx]); break;
			case 1:
				max_val = max(max_val, get_max(idx - 1) - nums[idx]); break;
			case 2:
				max_val = max(max_val, get_max(idx - 1) * nums[idx]); break;
			case 3:
				max_val = max(max_val, get_max(idx - 1) / nums[idx]); break;
			}
			operators[i]++;
		}
	}

	return max_val;
}

pair<int, int> get_min_max_calc() {
	
	return make_pair(get_max(N-1), get_min(N-1));
}

void data_in() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++)
		scanf("%d ", &nums[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d ", &operators[i]);

	pair<int, int> result = get_min_max_calc();

	printf("%d\n%d ", result.first, result.second);

}

int main() {

	data_in();
}
