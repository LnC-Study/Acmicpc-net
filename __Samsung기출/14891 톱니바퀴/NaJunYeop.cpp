#include <cstdio>
#include <cmath>
using namespace std;

int K, ans = 0;
int gear[4][8];

void rotate(int num, int dir) {
	int tmp;
	//clockwise
	if (dir == 1) {
		tmp = gear[num][0];
		for (int i = 7; i >= 1; i--) {
			gear[num][(i + 1) % 8] = gear[num][i];
		}
		gear[num][1] = tmp;
	}
	//counterclockwise
	else if (dir == -1) {
		tmp = gear[num][0];
		for (int i = 1; i <= 7; i++) {
			gear[num][(i + 7) % 8] = gear[num][i];
		}
		gear[num][7] = tmp;
	}
}
void left(int num, int dir)
{
	if (num > 0 && (gear[num - 1][2] != gear[num][6])) left(num - 1, dir * -1);
	rotate(num, dir);
}
void right(int num, int dir)
{
	if (num < 3 && (gear[num][2] != gear[num + 1][6])) right(num + 1, dir * -1);
	rotate(num, dir);
}
void solve(int num, int dir)
{
	if (num > 0 && (gear[num - 1][2] != gear[num][6])) left(num - 1, dir * -1);
	if (num < 3 && (gear[num][2] != gear[num + 1][6])) right(num + 1, dir * -1);
	rotate(num, dir);
}
int main()
{
	int num, dir;
	char str[9];

	for (int i = 0; i < 4; i++) {
		scanf("%s", &str);
		for (int j = 0; j < 8; j++) {
			gear[i][j] = str[j] - '0';
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &num, &dir);
		solve(num - 1, dir);
	}
	for (int i = 0; i < 4; i++) {
		if (gear[i][0]) ans += (int)pow(2, i);
	}

	printf("%d\n", ans);
	return 0;
}