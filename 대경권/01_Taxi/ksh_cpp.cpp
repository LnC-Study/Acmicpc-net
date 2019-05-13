#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	//1st. input
	vector<int> ary;
	int num = 0;
	do {
		cin >> num;
		ary.push_back(num);
	} while (getc(stdin) == ' ');

	//2nd. sort
	int groupNum = ary.size();
	sort(ary.begin(), ary.end());

	//3rd. matching
	int count = 0;
	int head = 0, tail = groupNum-1;
	while(head <= tail) {
		count++;
		if (head == tail)
			break;
		if (ary[head] + ary[tail] <= 4) {
			head++; tail--;
		}
		else if (ary[head] + ary[tail] > 4) {
			tail--;
		}
		cout << count << " ) " << head << " - " << tail << "\n";
	}

	cout << "\n" << count << "\n";

	return 0;
}

