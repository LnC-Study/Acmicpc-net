#include <stdio.h>
#include <stdlib.h>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void laserBeam(int **board, int n, int x, int y) {
    // board is 2dArray, n is board size, x and y are laserBeam location (x,y)
    
    int dir = 0;
    
    if(x == n+1) dir = UP;
    else if(x == 0) dir = DOWN;
    else if(y == n+1) dir = LEFT;
    else if(y == 0) dir = RIGHT;
    
    while(1) {
        
        if(dir == UP) x -= 1;
        else if(dir == DOWN) x += 1;
        else if(dir == LEFT) y -= 1;
        else if(dir == RIGHT) y += 1;
        
        if(board[x][y] == 1) {
            if(dir == UP) dir = RIGHT;
            else if(dir == DOWN) dir = LEFT;
            else if(dir == LEFT) dir = UP;
            else if(dir == RIGHT) dir = DOWN;
        }
        
        if(board[x][y] == -1) {
            printf("%d %d\n", x, y);
            break;
        }
    }
    
    return;
}

int main(void) {
    
    int testNum, n, r, x, y;
    int **board;
    
    scanf("%d", &testNum);
    
    for(int k=0; k<testNum; k++) {
        scanf("%d %d", &n, &r);
        
        board = (int **) malloc(sizeof(int *) * (n+2));
        
        for(int j=0; j<(n+2); j++) {
            board[j] = (int *) malloc(sizeof(int) * (n+2));
        }
        // making board --> n+2 * n+2
        
        for(int i=0; i <= n+1; i++) {
            for(int j=0; j <= n+1; j++) {
                
                if(i == 0 || i == n+1 || j == 0 || j == n+1){
                    board[i][j] = -1; // out of board
                }
                
                else board[i][j] = 0; // init board
            }
        }
        
        for(int j=0; j<r; j++) {
            scanf("%d %d", &x, &y);
            
            board[x][y] = 1; // marking location of mirror by 1
        }
        
        scanf("%d %d", &x, &y);
        
        
        laserBeam(board, n, x, y);
        
    }
    
    return 0;
}
