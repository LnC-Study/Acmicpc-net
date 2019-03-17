#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate_gear(int target, int direction);
void spin(int target, int direction);

int Gear[5][8] = {0};

int main(){
    int num = 0;
    int target = 0;
    int d = 0;
    int i = 0, j = 0;
    int answer = 0;
	char input[4][10];

    //톱니바퀴 초기화
	for(i=0; i<4; i++){
		scanf("%s", input[i]);
	}
    for(i = 1; i < 5; i++){
        for(j = 0; j < 8; j++){
			Gear[i][j] = input[i-1][j] - 48;
        }
    }
    
    //돌릴 횟수 초기화
    scanf("%d", &num);
    
    //돌리기
    for(i = 0; i < num; i++){
        scanf("%d %d", &target, &d);
        rotate_gear(target, d);
    }

    answer = Gear[1][0]*1 + Gear[2][0]*2 + Gear[3][0]*4 + Gear[4][0]*8;
    printf("%d\n", answer);
    
    return 0;
}
void rotate_gear(int target, int direction){

    int touch1 = 0, touch2 = 0, touch3 = 0;

    //접촉한 부분 초기화
    if(Gear[1][2] != Gear[2][6])
        touch1 = 1;
    if(Gear[2][2] != Gear[3][6])
        touch2 = 1;
    if(Gear[3][2] != Gear[4][6])
        touch3 = 1;
    
    //바퀴 돌리기
    switch(target){
        case 1:
            spin(1, direction);
            if(touch1 == 0)
                break;
            else{
                spin(2, -direction);
                if(touch2 == 0)
                    break;
                else{
                    spin(3, direction);
                    if(touch3 == 0)
                        break;
                    else
                        spin(4, -direction);
                }
            }
            break;
        case 2:
            spin(2, direction);
            if(touch1 == 1)
                spin(1, -direction);
            if(touch2 == 0)
                break;
            else{
                spin(3, -direction);
                if(touch3 == 0)
                    break;
                else
                    spin(4, direction);
            }
            break;
        case 3:
            spin(3, direction);
            if(touch3 == 1)
                spin(4, -direction);
            if(touch2 == 0)
                break;
            else{
                spin(2, -direction);
                if(touch1 == 0)
                    break;
                else
                    spin(1, direction);
            }
            break;
        case 4:
            spin(4, direction);
            if(touch3 == 0)
                break;
            else{
                spin(3, -direction);
                if(touch2 == 0)
                    break;
                else{
                    spin(2, direction);
                    if(touch1 == 0)
                        break;
                    else
                        spin(1, -direction);
                }
            }
            break;
    }
}
void spin(int target, int direction){

    int temp[8] = {0};
    int i = 0;
    
    if(direction == 1){
        temp[0] = Gear[target][7];
        for(i = 1; i < 8; i++)
            temp[i] = Gear[target][i-1];
    }
    else if(direction == -1){
        temp[7] = Gear[target][0];
        for(i = 0; i < 7; i++)
            temp[i] = Gear[target][i+1];
    }

    memcpy(Gear[target], temp, sizeof(temp));
}