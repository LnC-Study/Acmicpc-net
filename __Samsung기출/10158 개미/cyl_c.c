/* 시간 초과 ㅠㅠ,, 배열에 방문한 적 있는 좌표면 체크, 체크되어 있는 곳 재방문하면 멈추는 식으로 시간 줄여보려고 했는데 그러면 메모리 초과 ^^,,, */

#include <stdio.h>
#include <stdlib.h>
#define LEFTUP 1
#define LEFTDOWN 2 // In problem, it means RIGHTUP
#define RIGHTUP 3
#define RIGHTDOWN 4

void movingAnt(int w, int h, int p, int q, int t) {
    
    int dir = LEFTDOWN;
    
    while (t>0) {
        
        if(p == w && dir == LEFTDOWN) dir = RIGHTDOWN;
        else if(p == w && dir == LEFTUP) dir = RIGHTUP;
        
        else if(p == 0 && dir == RIGHTUP) dir = LEFTUP;
        else if(p == 0 && dir == RIGHTDOWN) dir = LEFTDOWN;
        
        else if(q == h && dir == RIGHTDOWN) dir = RIGHTUP;
        else if(q == h && dir == LEFTDOWN) dir = LEFTUP;
        
        else if(q == 0 && dir == RIGHTUP) dir = RIGHTDOWN;
        else if(q == 0 && dir == LEFTUP) dir = LEFTDOWN;
        
        if(dir == LEFTUP) {
            p += 1;
            q -= 1;
        }
        
        else if(dir == LEFTDOWN) {
            p += 1;
            q += 1;
        }
        
        else if(dir == RIGHTUP) {
            p -= 1;
            q -= 1;
        }
        
        else if(dir == RIGHTDOWN) {
            p -= 1;
            q += 1;
        }
        
        t--;
    }
    
    printf("%d %d", p, q);
    
    return;
}

int main() {
    
    int w, h, p, q, t; // w: array's weight, h: array's height, p: x, q: y, t: time/hour
    
    scanf("%d %d", &w, &h);
    
    scanf("%d %d %d", &p, &q, &t);
    
    movingAnt(w, h, p, q, t);
    
    return 0;
}
