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
	int count = 0, sum = 0;
	int head = 0, tail = groupNum-1;
	while (head <= tail) {
		if (sum + ary[head] + ary[tail] <= 4 && head != tail) {
			sum += (ary[head] + ary[tail]);
			//cout << ary[head] << " , " << ary[tail] << " , ";
			head++; tail--;
		}
		else if (sum + ary[tail] <= 4) {
			sum += ary[tail];
			//cout << ary[tail] << " , ";
			tail--;
		}
		else if (sum + ary[head] <= 4) {
			sum += ary[head];
			//cout << ary[head] << " , ";
			head++;
		}
		else {
			count++; sum = 0;
			//cout << "\n--- " << count << " ---\n\n";
		}
		//cout << "sum : " << sum << " / " << ary[head] << " - " << ary[tail] << "\n";
	}
	count++;

	cout << "\nres : " << count << "\n";

	return 0;
}

