#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))


int main(void) {
	int w, h;
	int cur_w, cur_h;
	int t;
	int cur_t = 0;
	int direction = 1;
	int dif_w, dif_h;
	scanf("%d %d\n", &w, &h);
	scanf("%d %d\n",&cur_w, &cur_h);
	scanf("%d\n", &t);

	while (cur_t < t) {
		if (direction == 1) {
			dif_w = w - cur_w;
			dif_h = h - cur_h;
				if ((t - cur_t) < min(dif_w, dif_h) ){
					cur_w = cur_w + (t - cur_t);
					cur_h = cur_h + (t - cur_t);
					break;
				}
		
				else if (w - cur_w > h - cur_h) {
				cur_w = cur_w + dif_h;
				cur_h = h;
				direction = 3;
				cur_t = cur_t + dif_h;
				}
				else {
					cur_w = w;
					cur_h = cur_h + dif_w;
					direction = 2;
					cur_t = cur_t + dif_w;
				}
				//print(cur_w, cur_h, direction, cur_t)
		}
		else if (direction == 2) {
			dif_w = cur_w;
			dif_h = h - cur_h;
			if ((t - cur_t) < min(dif_w, dif_h)) {
				cur_w = cur_w - (t - cur_t);
				cur_h = cur_h + (t - cur_t);
				break;
			}
			else if (dif_w < dif_h) {
				cur_w = cur_w - dif_w;
				cur_h = cur_h + dif_w;
				direction = 1;
				cur_t = cur_t + dif_w;
			}
			else {
				cur_w = cur_w - dif_h;
				cur_h = cur_h + dif_h;
				direction = 4;
				cur_t = cur_t + dif_h;
			}

		}
		else if (direction == 3) {
			dif_w = w - cur_w;
			dif_h = cur_h;
			if ((t - cur_t) < min(dif_w, dif_h)) {
				cur_w = cur_w + (t - cur_t);
				cur_h = cur_h - (t - cur_t);
				break;
			}
			else if (dif_w < dif_h) {
				cur_w = cur_w + dif_w;
				cur_h = cur_h - dif_w;
				direction = 4;
				cur_t = cur_t + dif_w;
			}
			else {
				cur_w = cur_w + dif_h;
				cur_h = cur_h - dif_h;
				direction = 1;
				cur_t = cur_t + dif_h;
			}
				//print(cur_w, cur_h, direction, cur_t)
		}
		else if (direction == 4) {
			dif_w = cur_w;
			dif_h = cur_h;
			if ((t - cur_t) < min(dif_w, dif_h)) {
				cur_w = cur_w - (t - cur_t);
				cur_h = cur_h - (t - cur_t);
				break;
			}
			else if (dif_w < dif_h) {
				cur_w = cur_w - dif_w;
				cur_h = cur_h - dif_w;
				direction = 3;
				cur_t = cur_t + dif_w;
			}
			else {
				cur_w = cur_w - dif_h;
				cur_h = cur_h - dif_h;
				direction = 2;
				cur_t = cur_t + dif_h;
			}
				//print(cur_w, cur_h, direction, cur_t)
		}
	}
	printf("%d %d", cur_w, cur_h);
	return 0;
}