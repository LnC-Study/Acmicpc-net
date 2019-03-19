#include <cstdio>
#include <algorithm>
#define MAX 2e9
#define MIN -2e9
using namespace std;

int N;
int A[12];
int op[4];
int max_ans = MIN, min_ans = MAX;

void solve(int num, int idx)
{
	if (idx == N) {
		max_ans = max(max_ans, num);
		min_ans = min(min_ans, num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			switch (i) {
			case 0: solve(num + A[idx], idx + 1); break;
			case 1: solve(num - A[idx], idx + 1); break;
			case 2: solve(num * A[idx], idx + 1); break;
			case 3: solve(num / A[idx], idx + 1); break;
			}
			op[i]++;
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &op[i]);

	solve(A[0], 1);

	printf("%d\n", max_ans);
	printf("%d\n", min_ans);

	return 0;
}