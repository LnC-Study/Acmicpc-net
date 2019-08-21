#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string white_pair(int n);
string black_pair(int n);

string b_cache[1001];
string w_cache[1001];

string normalize(string n) {

	for (int i = 0; i < n.size() - 1; i++) {
		if (n[i] > 10) {
			n[i] -= 10;
			n[i + 1] += 1;
		}
	}

	if (n[n.size() - 1] > 10) {
		n[n.size() - 1] -= 10;
		n.push_back(1);
	}

	return n;
}

string str_plus(string a, string b) {

	if (a.size() > b.size())
		return str_plus(b, a);

	string ret;

	for (int i = 0; i < a.size(); i++) {
		ret.push_back(a[i] + b[i]);
	}

	ret += b.substr(a.size());

	return normalize(ret);
}

string black_pair(int n) {
	if (n == 1 || n == 0)
		return string(1,0);

	if (n == 2 || n == 3)
		return string(1,1);

	string &ret = b_cache[n];
	if (ret != "")
		return ret;

	if (n % 2 == 0)
		return ret = str_plus(str_plus(black_pair(n - 1), white_pair(n - 1)), string(1,1));

	return ret = str_plus(black_pair(n - 1), white_pair(n - 1));
}

string white_pair(int n) {
	if (n == 1 || n == 0 || n == 2)
		return string(1,0);

	if (n == 3)
		return string(1,1);

	string &ret = w_cache[n];
	if (ret != "")
		return ret;

	return ret = str_plus(black_pair(n - 1), white_pair(n - 1));
}

int main() {
	int n;
	scanf_s("%d", &n);

	string result = black_pair(n);

	for (int i = result.size() - 1; i >= 0; i--)
		printf("%d", result[i]);
}