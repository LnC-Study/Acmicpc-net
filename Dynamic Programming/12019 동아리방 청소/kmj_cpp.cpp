//
// Problem 12019번: 동아리방 청소!
// Created by coldbrew on 2019-02-18.
// 시간초과
//
#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

vector<int> input;
int minDirt = INF;
vector<int> minDays;

int solution(vector<int> input, vector<int> days){
    int N = input.size();
    int totalSum = 0;
    int todaySum[N];
    int dirt[N];
    int index = 0;

    fill_n(todaySum, N, 0);
    fill_n(dirt, N, 0);

    for(int i = 0; i < N;i++){
        if(i < N-1) {
            if (days[index] == i) {
                dirt[i + 1] = 0;
                index++;
            } else{
                dirt[i + 1] = dirt[i] + input[i];
            }
        }
        todaySum[i] = dirt[i] * input[i];
        totalSum += todaySum[i];
    }

    return totalSum;
}

void doCombination(int combArr[], int n, int r, int index, int target, int arr[]) {
    if(r == 0){
        vector<int> temp(r);
        for(int i=0; i<index; i++) {
            temp.push_back(arr[combArr[i]]);
        }
        int result = solution(input, temp);
        if(minDirt > result) {
            minDirt = result;
            minDays = temp;
        }
    }else if(target == n) return;
    else{
        combArr[index] = target;
        doCombination(combArr, n, r-1, index+1, target+1, arr); // (i)
        doCombination(combArr, n, r, index, target+1, arr); //(ii)
    }
}

int main(){
    int N; // total days
    int M; // how many times to clean the room


    /* Get input data */
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N;i++){
        int temp;
        scanf("%d", &temp);
        input.push_back(temp);
    }

    /* Find solution */
    int arr[N];
    for(int i = 1; i < N;i++){
        arr[i-1] = i;   // from DAY1~ DAY(N-1)
    }
    int combArr[N];
    doCombination(combArr, N-1, M, 0, 0, arr);

    /* Print solution */
    printf("%d\n", minDirt);
    for(int i = 0; i < M; i++){
        printf("%d ", minDays[i]+1);
    }

    return 0;
}