#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> histogram;

long long max_rectangle(int start, int end) {

	if (start == end)
		return histogram[start];

	long long ret = 0;

	int mid = (start + end) / 2;
	ret = max(ret, max_rectangle(start, mid));
	ret = max(ret, max_rectangle(mid + 1, end));

	int left = mid;
	int right = mid + 1;

	long long height = min(histogram[left], histogram[right]);

	long long area = height * (right - left + 1);
	ret = max(ret, area);

	for (; !(left == start && right == end) ;) {
		
		if (left > start && right < end) {
			histogram[left - 1] > histogram[right + 1] ? left-- : right++;
			height = min(height, histogram[left]);
			height = min(height, histogram[right]);
		}
		else if (left > start) {
			left--;
			height = min(height, histogram[left]);
		}
		else {
			right++;
			height = min(height, histogram[right]);
		}

		area = height * (right - left + 1);
		ret = max(ret, area);

	}

	return ret;
}

void data_in() {

	freopen("input.txt", "r", stdin);

	while (true) {
		int N;
		scanf("%d ", &N);

		if (N == 0)
			break;

		histogram = vector<long long>(N);

		for (int i = 0; i < N; i++) {
			scanf("%lli ", &histogram[i]);
		}

		long long result = max_rectangle(0, N - 1);
		printf("%lli\n", result);

		histogram.erase(histogram.begin(), histogram.end());
	}
		
}

int main() {

	data_in();

}
