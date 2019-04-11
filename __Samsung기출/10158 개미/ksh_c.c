#include <stdio.h>

int main() {
	int w, h, x, y, t;
	scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);
	x = abs(w - abs(x + (t % (2 * w)) - w));
	y = abs(h - abs(y + (t % (2 * h)) - h));
	printf("%d %d", x, y);
	return 0;
}