#include <stdio.h>
#include <stdlib.h>

void mirror();
void search(int **map, int size, int start[2]);

int main(int argc, const char * argv[]) {
    int i;
    int tc;
    
    scanf("%d", &tc);
    
    for(i=0; i<tc; i++){
        mirror();
    }
}

void mirror(){
    int size;
    int mrr_num;
    int **map;
    int i,j;
    int tempx, tempy;
    int lzr_loc[2];
    
    scanf("%d %d", &size, &mrr_num);
    
    map = (int **)malloc(sizeof(int *)*(size+2));
    for(i=0; i<=size+1; i++)
        map[i] = (int *)malloc(sizeof(int)*(size+2));
    
    for(i=1;i<=size; i++){//map init
        for(j=1;j<=size;j++)
            map[i][j] = 0;
    }
    
    for(i=0;i<=size+1;i++){//bound
        map[0][i]=-1;
        map[size+1][i]=-1;
        map[i][0]=-1;
        map[i][size+1]=-1;
    }
    
    for(i=0; i<mrr_num; i++){//mirror
        scanf("%d %d", &tempx, &tempy);
        map[tempx][tempy] = 1;
    }
    
    scanf("%d %d", &lzr_loc[0], &lzr_loc[1]);
    
    search(map, size, lzr_loc);
}

void search(int **map, int size, int start[2]){
    int *now;
    int dir; //0up 1right 2down 3left
    
    now=(int *)malloc(sizeof(int)*2);
    now[0]=start[0];now[1]=start[1];
    if(now[0]==0) dir=2;
    else if(now[0]==size+1) dir=0;
    else if(now[1]==0) dir=1;
    else if(now[1]==size+1) dir=3;
    
    while(1){
        //move
        if(dir == 0) now[0] = now[0]-1;
        else if(dir == 1) now[1] = now[1]+1;
        else if(dir == 2) now[0] = now[0]+1;
        else if(dir == 3) now[1] = now[1]-1;
        
        //bound?
        if(map[now[0]][now[1]] == -1) break;
        //mirror?
        else if(map[now[0]][now[1]] == 1) dir = (dir+1)%4;
    }
    
    printf("%d %d\n",now[0],now[1]);
}
