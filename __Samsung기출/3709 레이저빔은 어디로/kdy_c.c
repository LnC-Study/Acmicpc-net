#include<stdio.h>

int main(void) {

	int test, n, r, x, y;
	int i, j, k;
	int p, q;
	int mv[2] = { 0, 0 };

	int xy[50][2] = { 0 };

	scanf("%d", &test);

	for (i = 0;i < test;i++) {
		scanf("%d %d", &n, &r);

		for (j = 0;j < r;j++) {
			scanf("%d %d", &xy[j][0], &xy[j][1]);
		}
		scanf("%d %d", &x, &y);

		p = x;
		q = y;

		mv[0] = 0;
		mv[1] = 0;

		if (x == n + 1)
			mv[0] = -1;
		else if (x == 0)
			mv[0] = 1;
		else if (y == n + 1)
			mv[1] = -1;
		else if (y == 0)
			mv[1] = 1;

		while (1) {
			p += mv[0];
			q += mv[1];
			if (p == 0 || q == 0 || q > n || p > n) {
				printf("%d %d\n", p, q);
				break;
			}
			if (p == x && q == y) {
				printf("0 0\n");
				break;
			}
			for (k = 0;k < r;k++) {
				if (p == xy[k][0] && q == xy[k][1]) {
					if (mv[0] == -1) {
						mv[0] = 0;
						mv[1] = 1;
						break;
					}
					else if (mv[0] == 1) {
						mv[0] = 0;
						mv[1] = -1;
						break;
					}
					else if (mv[1] == -1) {
						mv[0] = -1;
						mv[1] = 0;
						break;
					}
					else if (mv[1] == 1) {
						mv[0] = 1;
						mv[1] = 0;
						break;
					}
				}
			}
		}
	}

	return 0;
}