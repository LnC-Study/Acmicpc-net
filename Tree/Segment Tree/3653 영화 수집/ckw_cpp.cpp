#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAXFLAVOR 100000

using namespace std;


class RSQ {

private :
	int size;
	int nxtIdx;
	vector<int> rangeSum;
	vector<int> pos;

	int init(const vector<int>&arr, int node, int left, int right) {
		if (left == right)
			return rangeSum[node] = arr[left];

		int mid = (left + right) / 2;
		int leftSum = init(arr, node * 2, left , mid);
		int rightSum = init(arr, node * 2 + 1, mid + 1, right);

		return rangeSum[node] = leftSum + rightSum;
	}

	int query(int node, int left, int right, int nodeLeft, int nodeRight) {
		
		if (nodeRight < left || nodeLeft > right)
			return 0;

		if (nodeLeft >= left && nodeRight <= right)
			return rangeSum[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftSum = query(node * 2, left, right, nodeLeft, mid);
		int rightSum = query(node * 2 + 1, left, right, mid + 1, nodeRight);

		return leftSum + rightSum;
	}

	int update(int node, int idx, int val, int left, int right) {

		if (idx < left || idx > right)
			return rangeSum[node];

		if (left == right)
			return (rangeSum[node] += val);

		int mid = (left + right) / 2;
		int leftSum = update(node * 2, idx, val, left, mid);
		int rightSum = update(node * 2 + 1, idx, val, mid + 1, right);
		return rangeSum[node] = leftSum + rightSum;	
	}

	int update(int idx, int val) {
		return update(1, idx, val, 0, size - 1);
	}

public :
	RSQ(const vector<int>&arr, int m) {
		size = arr.size();
		nxtIdx = m-1;
		pos = vector<int>(size);
		for (int i = m; i < m + size; i++) pos[i-m] = i;
		rangeSum = vector<int>((size + m) * 4);
		init(arr, 1, 0, size - 1);
	}

	int query(int idx) {
		int p = pos[idx];
		int ret = query(1, 0, p-1, 0, size - 1);
		pos[idx] = nxtIdx;
		update(p, -1);
		update(nxtIdx--, 1);
		return ret;
	}

	

};

void data_in() {

	int T;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &T);

	for (int i = 0; i < T; i++) {
		int n, m;

		scanf("%d %d ", &n, &m);
		
		vector<int> part_tree(m, 0);
		vector<int> segment_tree(n, 1);
		
		part_tree.insert(part_tree.end(), segment_tree.begin(), segment_tree.end());

		RSQ tree(part_tree, m);

		for (int j = 0; j < m; j++) {
			int num;
			scanf("%d ", &num);
			printf("%d ", tree.query(num - 1));
		}

		printf("\n");

	}

}

int main() {

	data_in();

}
