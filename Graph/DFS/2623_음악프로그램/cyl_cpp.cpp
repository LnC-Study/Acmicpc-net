// 백준에서 런타임 에러 뜨는데 왜..?ㅠㅠㅠㅠ

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    
    int n, m;
    vector<vector<int>> graph;
    vector<int> indegree;
    
    scanf("%d %d", &n, &m);
  
    graph = vector<vector<int>>(n+1);
    indegree = vector<int>(n+1);
    
    for(int i=0; i<m; i++) {
        
        int num, start;
        
        scanf("%d %d", &num, &start);
        
        for(int j=0; j<num-1; j++) {
            
            int current;
            
            scanf("%d", &current);
            
            graph[start].push_back(current); // make graph
            indegree[current]++; // count indegree
            
            start = current;
            
        }
    } // input
    
    queue<int> search;
    queue<int> result;
    
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0)
            search.push(i);
    } // push a vertex which has 0 indegree
    
    for(int i=0; i<n; i++) {
        if(search.empty())
            break;

        int temp = search.front();
        result.push(temp);
        search.pop();
        
        for(int j=0; j<graph[temp].size(); j++) {
            int next = graph[temp][j];
            
            indegree[next] -= 1;
            
            if(indegree[next] == 0) {
                search.push(next);
            }
        }
    } // topological sort
    
    for(int i=0; i<n; i++) {
        printf("%d\n", result.front());
        result.pop();
    } // print result
    
    return 0;
    
}
