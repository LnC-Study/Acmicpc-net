#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>adj;
vector<int> indegree;

//인접리스트의 indegree를 줄이고, indegree가 0인 것이 2개이상이면 true를 반환한다.
bool decr_adj_indegree(int num) { 

	int cnt = 0;
	indegree[num]--; 

	for (int i = 0; i < adj[num].size(); i++) {
		if (adj[num][i]) {
			indegree[i]--;
			
			if (!indegree[i])
				cnt++;
		}
	}

	return cnt > 1;
}

queue<int> topologicalSort() {
	queue<int> search;
	queue<int> result;

	for (int i = 0; i < adj.size(); i++) {
		if (!indegree[i]) {
			search.push(i);

			if (decr_adj_indegree(i)) {
				queue<int> r;
				r.push(-1);
				return r;
			}
		}
	}

	while(!search.empty()){
	
		int here = search.front();
		search.pop();
		result.push(here);

		for (int i = 0; i < adj[here].size(); i++) {
			if(adj[here][i])
				if (!indegree[i]) {
					search.push(i);
					if (decr_adj_indegree(i)) {
						queue<int> r;
						r.push(-1);
						return r;
					}
				}
		}
	}

	return result;
}

void data_in() {

	int C;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &C);

	for (int i = 0; i < C; i++) {
		int n, m;
		scanf("%d ", &n);

		indegree = vector<int>(n, 0);
		adj = vector<vector<int>>(n,vector<int>(n,0));
		 
		for (int j = 0; j < n; j++) {
			scanf("%d ", &indegree[j]);
			indegree[j]--;
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (indegree[k] > indegree[j]) {
					adj[j][k]++;
				}
			}
		}

		scanf("%d ", &m);
		for (int j = 0; j < m; j++) {
			int win, lose;
			scanf("%d %d ", &win, &lose);
			win--;
			lose--;

			adj[win][lose]++;
			adj[lose][win]--;

			indegree[win]--;
			indegree[lose]++;
		}

		queue<int> result = topologicalSort();

		if (result.size() == 1) {
			if (result.front() == -1) {
				printf("?\n");
				continue;
			}
		}

		if (result.size() != n) {
			printf("IMPOSSIBLE");
			continue;
		}

		vector<int> rank = vector<int>(n);
		int cnt = 1;
		while (!result.empty()) {
			rank[result.front()] = cnt++;
			result.pop();
		}

		for (int i = 0; i < rank.size(); i++)
			printf("%d ", rank[i]);

		printf("\n");

	}
}

int main() {
	data_in();
}