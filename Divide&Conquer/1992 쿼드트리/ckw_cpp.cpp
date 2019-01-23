#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string quad[64];

//항상 정사각형
string quadtree(int left, int right, int up, int down) {

	char q_val = -1;

	for (int i = up; i < down; i++) {
		for (int j = left; j < right; j++) {

			if (q_val == -1)
				q_val = quad[i][j];

			else if (quad[i][j] != q_val)
			{
				int mid = (left + right) / 2;
				int mid_height = (up + down) / 2;
				return "(" + 
					quadtree(left, mid , up, mid_height) +
					quadtree(mid, right, up, mid_height) +
					quadtree(left, mid , mid_height, down) +
					quadtree(mid, right, mid_height, down) +
					")";
			}
		}
	}

	return string(1, quad[up][left]);
}

void data_in() {

	int N;
	
	freopen("input.txt", "r", stdin);

	scanf("%d ", &N);

	for (int i = 0; i < N; i++)
		cin >> quad[i];

	cout << quadtree(0, N, 0, N);

}

int main() {

	data_in();
}
