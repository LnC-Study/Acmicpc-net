#include <iostream>

int w, h;

void ant(int p, int q, int t){

	int direc = 0;
	int x = h-q, y = p;

	for(int i=0; i<t; i++){
		switch(direc){
			case 0: //RU
				x = x-1;
				y = y+1;
				if(x==0 && y==w)
					direc = 3;
				if(x==0)
					direc = 1;
				else if(y==w)
					direc = 2;
				if(x==0 && y==w)
					direc = 3;
				break;
			case 1: //RD
				x = x+1;
				y = y+1;
				if(x==h)
					direc = 0;
				else if(y==w)
					direc = 3;
				if(x==h && y==w)
					direc = 2;
				break;
			case 2: //LU
				x = x-1;
				y = y-1;
				if(x==0)
					direc = 3;
				else if(y==0)
					direc = 0;
				if(x==0 && y==0)
					direc = 1;
				break;
			case 3: //LD
				x = x+1;
				y = y-1;
				if(x==h)
					direc = 2;
				else if(y==0)
					direc = 1;
				if(x==h && y==0)
					direc = 0;
				break;
		}
	}

	std::cout<<y<<" "<<h-x<<"\n";
}

int main(){
	int p, q;
	int t;

	freopen("input2.txt","r",stdin);

	std::cin>>w>>h;
	std::cin>>p>>q;
	std::cin>>t;

	ant(p, q, t);

	return 0;
}