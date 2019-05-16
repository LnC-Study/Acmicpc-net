#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> m){
	int count = 0;
	sort(m.begin(), m.end());

	while(!m.empty()){
		if(m.back() == 4){
			count++;
			m.pop_back();
		}
		else if(m.back() == 3){
			count++;
			m.pop_back();
			if(m.front() == 1)
				m.erase(m.begin());
		}
		else if(m.back() == 2){
			count++;
			m.pop_back();
			if(m.empty() != 1){
				if(m.front() == 1){
					int sum = m.back();
					while(sum < 4 && m.front() == 1){
						sum += m.front();
						m.erase(m.begin());
					}
				}
				else if(m.front() == 2){
					if(m.size() >= 1)
						m.erase(m.begin());
				}
			}
		}
		else if(m.back() == 1){
			int sum = m.back();
			while(sum < 4 && m.front() == 1){
				sum+=m.front();
				m.erase(m.begin());
			}
			count++;
			m.pop_back();
		}
	}
	return count;
}
int main(){
	freopen("input3.txt","r",stdin);
	int n;
	std::cin>>n;
	vector<int> s(n);
	for(int i=0; i<n; i++)
		std::cin>>s[i];

	std::cout<<solution(s)<<endl;
	return 0;
}