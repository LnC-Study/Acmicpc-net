#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> s) {
	int answer = 0;
	vector<bool> taken = vector<bool>(s.size());

	sort(s.begin(),s.end(),desc);

	for (int i = 0; i < s.size(); i++) {

		if (taken[i])
			continue;

		int left = 4;
		left -= s[i];
		taken[i] = true;

		if (left == 0)//그룹이 4명일때
		{
			answer++;
			continue;
		}

		for (int j = i; j < s.size(); j++) {

			if (left - s[j] >= 0 && !taken[j]) {
				left -= s[j];
				taken[j] = true;

				if (left == 0)//그룹이 4명일때
				{
					break;
				}
			}
		}

		answer++;

	}

	return answer;
}
