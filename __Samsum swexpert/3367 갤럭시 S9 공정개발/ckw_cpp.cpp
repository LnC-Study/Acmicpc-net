#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct RSQ {
	vector<int> sum_tree;
	RSQ(){}
	RSQ(vector<int> tree) : sum_tree(tree.size()) {
		sum_tree[0] = tree[0];

		for (int i = 1; i < tree.size(); i++) {
			sum_tree[i] = tree[i] + sum_tree[i - 1];
		}
	}

	int sum(int left, int right) {
		if (left > 0)
			return sum_tree[right] - sum_tree[left - 1];

		return sum_tree[right];
	}
};

vector<int> parts;
RSQ sum_Q;

vector<vector<int>> cache;
int min_cost(int left, int right) {

	if (left == right)
		return 0;

	int &ret = cache[left][right];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = left; i <= right; i++) {
		ret = min(ret, min_cost(left, i) + min_cost(i + 1, right) + sum_Q.sum(left, right));
	}

	return ret;
}

void data_in() {

	int T,K;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &T);

	for (int i = 0; i < T; i++) {

		scanf("%d ", &K);

		cache = vector<vector<int>>(3000, vector<int>(3000, -1));

		parts = vector<int>(K);
		for (int j = 0; j < K; j++)
			scanf("%d ", &parts[j]);
		
		sum_Q = RSQ(parts);

		printf("#%d %d\n",i+1, K == 1 ? parts[0] : min_cost(0,K - 1));

		cache.clear();
	}
}

int main() {

	data_in();

}
