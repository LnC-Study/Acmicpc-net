#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int w, h;
    int p, q;
    int t;
    int dirw=1;
    int dirh=1;
    
    scanf("%d %d", &w, &h);
    scanf("%d %d", &p, &q);
    scanf("%d", &t);
    
    
    for(i=0;i<t;i++){
        if(p+dirw>w || p+dirw<0) dirw=-dirw;
        if(q+dirh>h || q+dirh<0) dirh=-dirh;
        p=p+dirw; q=q+dirh;
    }
    
    printf("%d %d\n", p, q);
    
    return 0;
}
