#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 100001
using namespace std;

int N, E;
vector<int> priority;
vector<vector<pair<int,int>>> graph;
long long cache[MAX];

long long max_priority(int pos) {
	
	if (pos == N)
		return priority[pos];

	long long &ret = cache[pos];
	if (ret != -1)
		return ret;

	for (int i = 0; i < graph[pos].size(); i++) {
		ret = max(ret, max_priority(graph[pos][i].first) + priority[pos] - graph[pos][i].second);
	}

	return ret == -1 ? priority[pos] : ret;
}

vector<int> reconstruct(int pos) {
	vector<int> ret;
	
	if (graph.size() > 1)
		for (int i = 0; i < graph[pos].size(); i++) {
			if (max_priority(pos) == max_priority(graph[pos][i].first) + priority[pos] - graph[pos][i].second)
			{
				ret.push_back(pos);
				vector<int> next = reconstruct(graph[pos][i].first);
				ret.insert(ret.end(), next.begin(), next.end());
				break;
			}
		}
	else
		ret.push_back(pos);

	if (ret.size() == 0)
		ret.push_back(pos);

	return ret;
}


void data_in() {

	int T;

	freopen("input.txt", "r", stdin);

	scanf("%d ", &T);

	for (int i = 0; i < T; i++) {
		memset(cache, -1, sizeof(int)* MAX);
		
		scanf("%d %d ", &N, &E);

		priority = vector<int>(N + 1);
		graph = vector<vector<pair<int, int>>>(E + 1);

		for (int j = 1; j <= N; j++)
			scanf("%d ", &priority[j]);

		for (int j = 0; j < E; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back(make_pair(b, c));
		}

		
		long long max_pri = max_priority(1);
		vector<int> path = reconstruct(1);

		printf("%lli %d \n", max_pri, path.size());

		for (int j = 0; j < path.size(); j++) {
			printf("%d ", path[j]);
		}
		printf("\n");

	}

}

int main() {

	data_in();

}