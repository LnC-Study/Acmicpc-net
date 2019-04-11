#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool board[52][52];

void data_in() {

	freopen("input.txt", "r", stdin);

	int w, h;
	int x, y;
	int time;
	
	scanf("%d %d ", &w, &h);
	scanf("%d %d ", &x, &y);
	scanf("%d ", &time);

	int ret_x = x + time;
	int ret_y = y + time;
	int det_x = ret_x / w;
	int det_y = ret_y / h;

	ret_x %= w;
	ret_y %= h;

	if (det_x % 2 == 1)
		ret_x = w - ret_x;

	if (det_y % 2 == 1)
		ret_y = h - ret_y;

	printf("%d %d ", ret_x, ret_y);

}

int main() {
	data_in();
}
