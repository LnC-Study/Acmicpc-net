#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAXFLAVOR 1000000

using namespace std;


class RSQ {

private :
	int size;
	vector<int> rangeSum;

	int init(const vector<int>&arr, int node, int left, int right) {

		if (left == right)
			return rangeSum[node] = arr[left];

		int mid = (left + right) / 2;
		int leftSum = init(arr, node * 2, left , mid);
		int rightSum = init(arr, node * 2 + 1, mid + 1, right);

		return rangeSum[node] = leftSum + rightSum;
	}

	int query(int node, int cnt, int nodeLeft, int nodeRight) {

		if (nodeLeft == nodeRight) {
			update(nodeLeft, -1);
			return nodeLeft;
		}

		int mid = (nodeLeft + nodeRight) / 2;

		if (rangeSum[node * 2] < cnt)
			return query(node * 2 + 1, cnt - rangeSum[node * 2], mid + 1, nodeRight);
		else
			return query(node * 2, cnt, nodeLeft, mid);
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

public :
	RSQ(const vector<int>&arr) {
		size = arr.size();
		rangeSum = vector<int>(size * 4);
		init(arr, 1, 0, size - 1);
	}

	int query(int cnt) {
		return query(1, cnt, 0, size - 1);
	}

	int update(int idx, int val) {
		return update(1, idx, val, 0, size - 1);
	}

};

void data_in() {

	int n;
	vector<int> segment_tree(MAXFLAVOR);
	RSQ tree(segment_tree);

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		int type;
		scanf("%d ", &type);

		if (type == 1) {
			int pick;
			scanf("%d ", &pick);

			printf("%d\n", tree.query(pick));
		}
		else if (type == 2) {
			int flavor, nums;

			scanf("%d %d ", &flavor, &nums);

			tree.update(flavor, nums);
		}
		
	}

}

int main() {

	data_in();

}
