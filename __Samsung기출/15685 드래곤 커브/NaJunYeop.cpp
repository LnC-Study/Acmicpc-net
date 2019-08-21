#include <cstdio>
#include <vector>
#define MAX 101
using namespace std;

int N;
bool m[MAX][MAX];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

bool out(int y, int x) { return (y < 0 || y > MAX - 1 || x < 0 || x > MAX - 1); }
int gans()
{
	int ret = 0;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (m[i][j] && m[i][j + 1] && m[i + 1][j] && m[i + 1][j + 1]) ret++;
		}
	}
	return ret;
}
void curving(int y, int x, int d, int g)
{
	vector<int> stack;
	int cnt = 0, top = -1, dir;

	m[y][x] = true;

	y += dy[d], x += dx[d];
	if (!out(y, x)) m[y][x] = true;

	stack.push_back(d), top++;

	if (g == 0) return;

	while (1) {
		cnt++;

		for (int i = top; i > -1; i--) {
			dir = (stack[i] + 1) % 4;
			stack.push_back(dir), top++;

			y += dy[dir], x += dx[dir];
			if (!out(y, x)) m[y][x] = true;
		}
		if (cnt == g) break;
	}
}
int main()
{
	int y, x, d, g;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		curving(y, x, d, g);
	}

	printf("%d\n", gans());
	return 0;
}