#include<stdio.h>

int main(void) {

	int w, h, p, q, t;
	int i;
	int x = 0;
	int x_mod = 0;
	int y = 0;
	int y_mod = 0;

	scanf_s("%d %d", &w, &h);
	scanf_s("%d %d", &p, &q);
	scanf_s("%d", &t);

	t -= (w - p);
	x = t / w;
	x_mod = t % w;
	t += (w - p);
	y = (t - (h - q)) / h;
	y_mod = (t - (h - q)) % h;

	if (x % 2 != 0)
		p = x_mod;
	else
		p = abs(w - x_mod);

	if (y % 2 != 0)
		q = y_mod;
	else
		q = abs(h - y_mod);

	printf("%d %d\n", p, q);

	return 0;
}