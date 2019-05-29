#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {

	set<string> ary;
	int testCaseNum = 0;
	cin >> testCaseNum;
	int N = 0;
	char c_element[51];
	string s_element, it;
	set<string>::iterator iter;
	for (int test = 0; test < testCaseNum; test++) {
		cin >> N;
		cin.ignore();
		ary.clear();
		for (int i = 0; i < N; i++) {
			cin >> c_element;
			s_element = c_element;
			ary.insert(s_element);
			//printf("%d : %s\n", i + 1, s_element.c_str());
		}

		printf("#%d\n", test + 1);
		
		for (iter = ary.begin(); iter != ary.end(); ++iter) {
			it = *iter;
			printf("%s\n", it.c_str());
		}
	}

	return 0;
}


