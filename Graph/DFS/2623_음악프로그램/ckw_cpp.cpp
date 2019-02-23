#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

void pick_num(int num) {	for (int i = 0; i < adj[num].size(); i++) indegree[adj[num][i]]--;	}

queue<int> topologicalSort() {
	
	queue<int> search;
	queue<int> result;

	for (int i = 0; i < adj.size(); i++) {
		if (!indegree[i]) {
			search.push(i);
			indegree[i]--;
			pick_num(i);
		}
	}

	while (!search.empty()) {
		int here = search.front();
		search.pop();
		result.push(here);

		for (int i = 0; i < adj[here].size(); i++) {
			if (!indegree[adj[here][i]]) {
				indegree[adj[here][i]]--;
				search.push(adj[here][i]);
				pick_num(adj[here][i]);
			}
		}
	}

	return result;
}

void data_in() {
	int N, M;
    
	scanf("%d %d ", &N, &M);

	adj = vector<vector<int>>(N);
	indegree = vector<int>(N);
	for (int i = 0; i < M; i++) {
		int n, prev;

		scanf("%d %d ", &n, &prev);

		prev--;

		for (int j = 0; j < n - 1 ; j++) {
			int to, from;

			scanf("%d ", &to);
			
			to--;
			from = prev;

			adj[from].push_back(to);
			indegree[to]++;

			prev = to;
		}
	}

	queue<int> result = topologicalSort();

	if (result.size() != N) {
		printf("0");
		return;
	}

	while (!result.empty()) {
		printf("%d\n", result.front() + 1);
		result.pop();
	}
}

int main() {

	data_in();
}
