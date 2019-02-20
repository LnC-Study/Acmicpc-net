# 2623번: 음악프로그램

def dfs(curNode):
    visited[curNode] = 1

    for nextNode in graph[curNode]:
        if visited[nextNode] != 1:  # unvisited node
            dfs(nextNode)
        else:
            if finish[nextNode] != 1:
                cycle = 1

    finish[curNode] = 1
    stack.append(curNode)



def get_input():
    N, M = map(int, input().split())
    graph = list(list() for i in range(N+1))

    for i in range(M):
        temp = input().split()
        for i in range(1, len(temp)):
            cur = int(temp[i])
            if i != 1:
                graph[prev].append(cur)
            prev = cur

    return graph

if __name__ == '__main__':
    graph = get_input()

    visited = list(0 for i in range(0, len(graph)))
    finish = list(0 for i in range(0, len(graph)))
    stack = list()
    cycle = 0

    for i in range(1, len(graph)):
        if visited[i] != 1:
            dfs(i)

    if cycle == 1:
        print("0")
    else:
        stack.reverse()
        for i in range(0, len(graph)-1):
            print(stack[i])
