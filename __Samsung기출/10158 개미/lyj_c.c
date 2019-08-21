#include <stdio.h>
#include <stdlib.h>

int main() {
    int w, h;
    int p, q;
    int t;
    int x, y;
    
    scanf("%d %d", &w, &h);
    scanf("%d %d", &p, &q);
    scanf("%d", &t);
    
    if(!(((p+t)/w)%2))//양 옆으로 몇 번 부딪히는지? 두 번 부딪히면 같은방향
        x = (p+t)%w;
    else
        x = w-((p+t)%w);
    if(!(((q+t)/h)%2))// 위 아래로 몇 번 부딪히는지? 두 번 부딪히면 같은방향
        y=(q+t)%h;
    else
        y=h-((q+t)%h);
    
    printf("%d %d\n", x, y);
    
    return 0;
}
