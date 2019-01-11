#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>
#define MAX 300000
using namespace std;

vector<int> little_boy;
int cap[10001];

int is_pretty(int begin, int end) {

	for (int i = begin; i <= end; i++) {
		int idx = little_boy[i];
		cap[idx]++;

		if (cap[idx] > (end - begin + 1) / 2)
			return idx;
	}

	return 0;
}

void data_in() {

	int C, N, M;

	scanf("%d %d ",&N, &C);
	little_boy = vector<int>(N + 1);
	
	for (int i = 1; i <= N; i++) {
		
		scanf("%d ", &little_boy[i]);

	}

	scanf("%d ", &M);

	for (int i = 0; i < M; i++) {
		int begin, end;

		memset(cap,0,sizeof(int) * (C + 1));

		scanf("%d %d ", &begin, &end);

		int result = is_pretty(begin, end);
		printf( !result ? "%s","no\n" : "%s %d\n","yes",result);
	}
}

int main() {

	data_in();

}
