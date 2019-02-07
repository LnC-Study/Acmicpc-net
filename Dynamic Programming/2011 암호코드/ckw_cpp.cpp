#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#define MAXN 5001
#define MOD 1000000
using namespace std;

int cache[MAXN];
string str;
bool is_successive = true;

int interprete(int idx) {

	if (!is_successive)
		return -1;

	int &ret = cache[idx];
	if (ret != -1)
		return ret;

	if (idx == str.size())
		return ret = 1;

	if (idx > str.size())
		return ret = 0;

	if (str[idx] == '0') {
		if (idx > 0)
			if (str[idx - 1] > 2)
				return ret = 0;
			else {
				is_successive = false;
				return -1;
			}
		return 0;
	}

	if (str[idx] == '1')
		return ret = (interprete(idx + 1) + interprete(idx + 2)) % MOD;

	if (str[idx] == '2')
		if(str[idx + 1] <= '6' && str[idx + 1] != 0)
			return ret = (interprete(idx + 1) + interprete(idx + 2)) % MOD;

	return ret = interprete(idx + 1) % MOD;
}

void data_in() {

	memset(cache, -1, sizeof(int)*MAXN);

	cin >> str;
	int result = interprete(0);
	printf("%d", is_successive ? result : 0);

}

int main() {

	data_in();
}
