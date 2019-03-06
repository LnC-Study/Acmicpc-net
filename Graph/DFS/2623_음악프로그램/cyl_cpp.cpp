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
    
    bool flag = true; // check whether we can do topological sort or not
    
    for(int i=0; i<n; i++) {
        if(search.empty()) {
            flag = false; // cannot 
            break;
        }

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
    
    if(!flag) {
        printf("0");
        return 0;
    }
    
    for(int i=0; i<n; i++) {
        printf("%d\n", result.front());
        result.pop();
    } // print result
    
    return 0;
    
}
