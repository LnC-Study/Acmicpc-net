#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = 987654321;
const int MAX_N = 15;
int N;
int T[MAX_N];
int P[MAX_N];

int cache[MAX_N];

int max_property(int day) {

	if (day >= N)
		return 0;

	int &ret = cache[day];
	if (ret != -1)
		return ret;

	int select = 0;

	//해당 날짜를 선택
	if(day + T[day] <= N)
		select = P[day] + max_property(day + T[day]);

	ret = max(select, max_property(day + 1));

	return ret;
}

void data_in() {

	memset(cache, -1, sizeof(cache));

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &T[i], &P[i]);
	}

	printf("%d ", max_property(0));
}

int main() {

	data_in();

}
