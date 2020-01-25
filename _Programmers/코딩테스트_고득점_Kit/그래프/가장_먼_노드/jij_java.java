package programmers;

import java.util.ArrayList;
import java.util.HashMap;

public class Q14 {
	int max = 0;
	
	enum Color {
		WHITE, BLACK, GRAY
	}
	
	class Vertex {
		int num;
		Color color;
		int distance;
		Vertex preVertex;
		
		Vertex(int num) {
			this.num = num;
			this.color = Color.WHITE;
			this.distance = 0;
			this.preVertex = null;
		}
	}
	
    public int solution(int n, int[][] edge) {
    	int answer = 0;
    	
        /* initialize all vertices */
    	HashMap<Integer, Vertex> vertices = new HashMap<Integer, Vertex>();
    	for (int i = 1; i <= n; i++)
    		vertices.put(i, new Vertex(i));
    	
    	/* initialize the graph */
    	HashMap<Vertex, ArrayList<Vertex>> graph = new HashMap<Vertex, ArrayList<Vertex>>();
        for (int i = 1; i <= n; i++)
        	graph.put(vertices.get(i), new ArrayList<Vertex>());
        
        /* make all edges in the graph */
        for (int[] e : edge) {
        	int source = e[0], destination = e[1];
        	graph.get(vertices.get(source)).add(vertices.get(destination));
        	graph.get(vertices.get(destination)).add(vertices.get(source));
        }
        
        /* solve the problem by using BFS */
        BFS(vertices, graph, 1);
        
        for (Vertex vertex : vertices.values()) {
        	if (vertex.distance == max) answer++;
        }
        
        return answer;
    }
    
    private void BFS(HashMap<Integer, Vertex> vertices, HashMap<Vertex, ArrayList<Vertex>> graph, int source) {
    	Vertex vertex;
    	ArrayList<Vertex> queue = new ArrayList<Vertex>();
    	vertices.get(source).color = Color.GRAY;    	
    	
    	/* enqueue */
    	queue.add(vertices.get(source));
    	
    	while (!queue.isEmpty()) {
    		
    		/* dequeue */
    		vertex = queue.get(0);
    		queue.remove(0);
    		
    		for (Vertex adj : graph.get(vertex)) {
    			if (adj.color == Color.WHITE) {
    				adj.color = Color.GRAY;
    				adj.distance = vertex.distance + 1;
    				adj.preVertex = vertex;
    				queue.add(adj);
    				max = Math.max(max, adj.distance);
    			}
    		}

    		vertex.color = Color.BLACK;
    	}
    }
}
