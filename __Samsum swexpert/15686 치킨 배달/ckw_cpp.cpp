#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 50;
const int MAX_HOUSE = 2 * MAX_N;
const int MAX_CHICKEN = 13;

int N, M;
int board[MAX_N][MAX_N];

int chicken_distance[MAX_HOUSE][MAX_CHICKEN];
vector<bool> picked_chicken;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;


int get_distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int min_total_distance() {

	picked_chicken = vector<bool>(chicken.size(), false);
	for (int i = 0; i < M; i++) picked_chicken[i] = true;

	int ret = INF;
	do {
		vector<int> min_dist = vector<int>(house.size(), INF);
		int tmp = 0;

		for (int i = 0; i < chicken.size(); i++) {
			if (picked_chicken[i]) {
				for (int j = 0; j < house.size(); j++)
					min_dist[j] = min(min_dist[j], chicken_distance[j][i]);
			}
		}

		for (int i = 0; i < house.size(); i++)
			tmp += min_dist[i];

		ret = min(ret, tmp);

	}while (prev_permutation(picked_chicken.begin(), picked_chicken.end()));

	return ret;
}

void data_in() {
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d ", &board[i][j]);

			switch (board[i][j])
			{
			case 1: house.push_back(make_pair(i, j)); break;
			case 2: chicken.push_back(make_pair(i, j)); break;
			}
		}	

	for (int i = 0; i < house.size(); i++) {
		int min_distance = INF;
		for (int j = 0; j < chicken.size(); j++) {
			chicken_distance[i][j] = get_distance(house[i], chicken[j]);
		}
	}

	printf("%d ", min_total_distance());
	
}

int main() {

	data_in();
}
