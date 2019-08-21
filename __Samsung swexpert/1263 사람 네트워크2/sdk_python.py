def data_in():
    data = list(map(int, input().split()))
    N, connected_comps = data[0], data[1:]

    return N, connected_comps

def make_graph(connected_comps):
    return [connected_comps[node_idx*num_of_nodes:(node_idx+1)*num_of_nodes] for node_idx in range(num_of_nodes)]

def get_cc_from_start(start_node):
    visited = [False for _ in range(num_of_nodes)]
    distances = [0 for _ in range(num_of_nodes)]

    queue, visited[start_node] = [start_node], True
    while len(queue) > 0:
        current = queue[0]
        del queue[0]

        for node, is_connected in enumerate(graph[current]):
            if not is_connected: continue
            if not visited[node]:
                visited[node] = True
                distances[node] = distances[current] + 1
                queue.append(node)

    return sum(distances)

def solution():
    return min(map(get_cc_from_start, range(num_of_nodes)))

if __name__ == '__main__':
    global num_of_nodes, graph

    test_case = int(input())
    for case_number in range(1, test_case + 1):
        num_of_nodes, connected_comps = data_in()
        graph = make_graph(connected_comps)
        ans = solution()
        print(f'#{case_number} {ans}')