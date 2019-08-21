#include <vector>
#include <string>
#include <iostream>

using namespace std;

int num_of_parens;
vector<string> str;

void make_parens_set(int open, int close, int rest, string cur_str) {

	if (close == num_of_parens)
		str.push_back(cur_str);

	if (rest > 0)
		make_parens_set(open + 1, close, rest - 1, cur_str + '(');

	if (open > close)
		make_parens_set(open, close + 1, rest, cur_str + ')');

}


vector<string> solution(int N)
{	

	num_of_parens = N;

	make_parens_set(0,0,num_of_parens,"");
	
	return str;
}
