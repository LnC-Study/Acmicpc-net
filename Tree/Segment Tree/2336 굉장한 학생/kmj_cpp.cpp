// 2336: 굉장한 학생

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 987654321

using namespace std;
struct student{
    int gradeA; // score of 1th test.
    int gradeB; // score of 2nd test.
    int gradeC; // score of 3rd test.
};

int findMin(vector<int> &tree, int cur_node, int start, int end, int left, int right){
    // cur_node: index of current node.
    // start, end: current node is charge of range[start, end].
    // left, right: want to find minimum value in range[left, right].
    if( (end < left) || (right < start)){   // totally out of range
        return INF;
    }
    else if( (left <= start) && (end <= right)){  // [start, end] is in [left, right]
        return tree[cur_node];
    }
    else{   // [left, right]  is in [start, end] OR overlap in scope.
        return min( findMin(tree, 2*cur_node, start, (start+end)/2, left, right),
                    findMin(tree, 2*cur_node+1, (start+end)/2+1, end, left, right) );
    }
}

int update(vector<int> &tree, int position, int value, int cur_node, int start, int end){
    // position: node number that you want to update.
    // value: number that you want to put in tree[position].
    // cur_node: index of current node.
    // start, end: current node is charge of range[start, end].
    if( (position < start) || (end < position)){
        return tree[cur_node];
    }
    else if(start == end){
        return tree[cur_node] = value;
    }
    return tree[cur_node] = min(update(tree, position, value, 2*cur_node, start, (start+end)/2),
                                update(tree, position, value, 2*cur_node+1, (start+end)/2+1, end));
}

bool compare(student a, student b){
    return a.gradeA < b.gradeA;
}

int main(){
    /* 1. Get input */
    int N;
    scanf("%d", &N);
    vector<student> students(N+1);  // index 0 will not use.
    for(int grade = 1; grade <= N; grade++){
        int student_id;
        scanf("%d", &student_id);
        students[student_id].gradeA = grade;
    }
    for(int grade = 1; grade <= N; grade++){
        int student_id;
        scanf("%d", &student_id);
        students[student_id].gradeB = grade;
    }
    for(int grade = 1; grade <= N; grade++){
        int student_id;
        scanf("%d", &student_id);
        students[student_id].gradeC = grade;
    }

    // create segment tree(RMQ:Range Minimum Query)
    int tree_height = (int)ceil(log2(N));
    int tree_size = (1 << (tree_height+1));
    vector<int> tree(tree_size);

    // sorting by scoreA ascending
    sort(students.begin(), students.end(), compare);

    /* 2. find brilliant students */
    int result = 0;

    // initialize tree to INF
    for(int i = 1; i <= N; i++){
        update(tree, i, INF, 1, 1, N);
    }


    for(int i = 1; i <= N; i++){
        if( findMin(tree, 1, 1, N, 1, students[i].gradeB) > students[i].gradeC){
            result++;
        }
        update(tree, students[i].gradeB, students[i].gradeC, 1, 1, N);
    }

    printf("%d", result);

    return 0;
}
