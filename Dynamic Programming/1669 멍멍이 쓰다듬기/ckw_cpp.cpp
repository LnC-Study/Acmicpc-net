#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long min_day(long long left) {

	if (left == 1)
		return 1;
	else if (left == 0)
		return 0;

	long long prev_n = -1;
	long long n;

	for (n = sqrt(left) - 1; n*(n + 1) < left; n++);

	n--;

	if (left - n * (n + 1) <= n + 1)
		return (n + 1) * 2 - 1;
	else
		return (n + 1) * 2;


}

void data_in() {

	int X, Y;

	scanf("%d %d", &X, &Y);

	printf("%lli ", min_day(Y - X));
}

int main() {

	data_in();

}
