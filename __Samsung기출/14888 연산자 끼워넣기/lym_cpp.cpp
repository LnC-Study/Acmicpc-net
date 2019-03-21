#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;
	int i, j, k;
	int num[15] = {0};
	int oper[4] = {0};
	int plus = 20;
	int cal = 0;
	int min = 2e9;
	int max = -2e9;

	//freopen("input.txt","r",stdin);

	scanf("%d", &n);
	
	vector<int> v(n-1);

	for(i=0; i<n; i++)
		scanf("%d", &num[i]);
	for(i=0; i<4; i++)
		scanf("%d", &oper[i]);

	k = 0;
	for(i=0; i<4;i++){
		if(oper[i] != 0){
			for(j=0; j < oper[i]; j++){
				v[k] = plus;
				k++;
			}
		}
		plus++;
	}

	do{
		for(i=0; i< n-1; i++){
			switch(v[i]){
			case 20: // plus
				if(i == 0){
					cal = num[i] + num[i+1];
				}
				else{
					cal += num[i+1];
				}
				break;
			case 21: // minus
				if(i == 0){
					cal = num[i] - num[i+1];
				}
				else{
					cal -= num[i+1];
				}
				break;
			case 22: // multiply
				if(i == 0){
					cal = num[i] * num[i+1];
				}
				else{
					cal *= num[i+1];
				}
				break;
			case 23: //divide
				if(i == 0){
					cal = num[i] / num[i+1];
				}
				else{
					cal /= num[i+1];
				}
				break;
			}
		}

		if(cal < min)
			min = cal;
		if(cal > max)
			max = cal;

	}while(next_permutation(v.begin(),v.end()));

	printf("%d\n%d\n", max, min);

	return 0;
}