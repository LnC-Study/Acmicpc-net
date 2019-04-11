#include<stdio.h>

int main(void) {

	int w, h, p, q, t;
	int i;
	int x = 1;
	int y = 1;

	scanf_s("%d %d", &w, &h);
	scanf_s("%d %d", &p, &q);
	scanf_s("%d", &t);

	for (i = 0;i < t;i++) {
		if (p == w || p == 0) {
			x = -(x);
		}
		else if (q == 0 || q == h) {
			y = -(y);
		}
		p += x;
		q += y;
	}

	printf("%d %d\n", p, q);

	return 0;
}