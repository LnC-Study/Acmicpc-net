#include <vector>
#include <iostream>

using namespace std;

int n, r;
int x, y;
int laser_x, laser_y;

void Laser(vector<vector<int>> &b, int lx, int ly){

	int nx = lx, ny = ly;
	int direc;
	int flag = 0;

	if(nx == 0)
		direc = 3; //D
	else if(nx == n+1)
		direc = 2; //U
	else if(ny == 0)
		direc = 1; //R
	else if(ny == n+1)
		direc = 0; //L

	while(1){
		if(flag == 1)
			break;

		switch(direc){
			case 0://L
				nx = nx;
				ny = ny-1;
				if(ny == 0)
					flag = 1;
				if(b[nx][ny] == 1)
					direc = 2;
				break;
			case 1://R
				nx = nx;
				ny = ny+1;
				if(ny == n+1)
					flag = 1;
				if(b[nx][ny] == 1)
					direc = 3;
				break;
			case 2://U
				nx = nx-1;
				ny = ny;
				if(nx == 0)
					flag = 1;
				if (b[nx][ny] == 1)
					direc = 1;
				break;
			case 3://D
				nx = nx+1;
				ny = ny;
				if(nx == n+1)
					flag = 1;
				if(b[nx][ny] == 1)
					direc = 0;
				break;
		}
	}

	std::cout<<nx<<" "<<ny<<std::endl;
}

int main(){

	int test_num;

	freopen("input.txt","r",stdin);

	std::cin>>test_num;

	for(int i=0; i<test_num; i++){
		std::cin>>n>>r;

		vector<vector<int>> board(n+2, vector<int>(n+2, 0));
		
		for(int j=0; j<r; j++){
			std::cin>>x>>y;
			board[x][y] = 1;
		}
		
		std::cin>>laser_x>>laser_y;

		Laser(board, laser_x, laser_y);
	}
	return 0;
}