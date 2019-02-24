#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<long long>Ai;
long long B, C;

long long min_observer() {
	long long sum = 0;

	for (int i = 0; i < Ai.size(); i++) {
		long long stds = Ai[i];

		stds -= B;
		sum++;

		long long sub_ob = stds / C;
		if(sub_ob > 0)
			sum += sub_ob;

		if (stds % C > 0)
			sum++;
	}

	return sum;
}

void data_in() {

	int N;

	scanf("%d ", &N);

	Ai = vector<long long>(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld ", &Ai[i]);
	}

	scanf("%lld %lld ", &B, &C);
	
	printf("%lld ", min_observer());
}

int main() {

	data_in();

}
