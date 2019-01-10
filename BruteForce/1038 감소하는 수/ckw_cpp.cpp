#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX 11

using namespace std;

int bino[MAX][MAX];

void calc_bino() {
	for (int i = 0; i < MAX; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = bino[i - 1][j - 1] + bino[i - 1][j];
		}
	}
}

long long decreasing_num(int num) {

	int height = 0;
	long long ret = 0;
	vector<int> nums(10);

	if (num >= 1023)
		return -1;

	if (num < 11)
		return num;

	for (height = 1; num >= bino[10][height]; height++) {
		num -= bino[10][height];
	}

	for (int i = 0; i < height; i++) {
		nums[i] = 1;
	}

	for (int i = 0; i <= num; i++) {
		next_permutation(nums.begin(), nums.end());
	}

	for (int i = 9, j = 0, k = 0; i >= 0; i--, j++) {
		if (nums[i] == 1)
			ret += pow(10.0, k++) * j;
	}


	return ret;
}

void data_in() {
	int N;
	scanf("%d", &N);
	printf("%lli", decreasing_num(N));
}

int main() {
	calc_bino();
	data_in();
}
