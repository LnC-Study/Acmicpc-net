package programmers;

public class Q3 {
	public static void main(String[] args) {
		int[] scoville = {1,2,3,9,10,12};
		
		Q3 q3 = new Q3();
		Q3.Solution sol = q3.new Solution();
		
		int answer = sol.solution(scoville, 7);
		
		System.out.println(answer);
		
		
	}
	
	class Solution {
		final int MAX = 1000000001;
		public int solution(int[] scoville, int K) {
			int answer = 0;
			
			int[] heap = new int[scoville.length + 1]; // initialize min heap
			int size = 0;	// current the size of heap
			int idx;	// the index of node
			int temp;
			int first;	// 가장 작은 스코빌 지수
			int second;	// 두 번째로 작은 스코빌 지수
			
			// push the data into heap
			for (int sco : scoville) {
				size++;
				heap = insert(heap, sco, size);
			}
			
			// check that the minimum value is not more or equal than K 
			while (true) {
				if (heap[1] >= K) {
					break;
				} else if (size < 2) {
					answer = -1;
					break;
				} else {
					// 가장 작은 갑과 두번째로 작은 값 remove
					first = heap[1];
					heap[1] = heap[size--];
					heap[size + 1] = MAX;
					
					// fix the root of heap
					heap = fix_root(heap, size);
					
					second = heap[1];
					heap[1] = heap[size--];
					heap[size + 1] = MAX;
					
					// fix the root of heap
					heap = fix_root(heap, size);
					
					// push new sco = first + (2 * second) into heap
					size++;
					heap = insert(heap, first + (2 * second), size);
					
					answer++;
				}
			}
			
			return answer;
		}
		
		public int[] insert(int[] heap, int newInt, int size) {
			heap[size] = newInt;
			int idx = size;
			int temp;
			
			while ((idx >> 1) > 0 && heap[idx] < heap[idx >> 1]) {
				temp = heap[idx];
				heap[idx] = heap[idx >> 1];
				heap[idx >> 1] = temp;
				idx = idx >> 1;
			}
			
			return heap;
		}
		
		public int[] fix_root(int[] heap, int size) {
			int idx = 1;
			int temp;
			
			while (2*idx <= size) {
				// 더 작은 값을 가지는 자식 노드 선택
				temp = heap[2*idx] < heap[2*idx + 1] ? heap[2*idx] : heap[2*idx + 1];
				
				// 자식 노드들이 부모 노드보다 큰 경우에만 수행
				if (heap[idx] < temp) {
					break;
				} else {
					// 더 작은 값을 갖는 자식 노드가 왼쪽 자식 노드인 경우
					if (temp == heap[2*idx]) {
						heap[2*idx] = heap[idx];
						heap[idx] = temp;
						idx = 2*idx;
					} else {
						heap[2*idx + 1] = heap[idx];
						heap[idx] = temp;
						idx = 2*idx + 1;
					}
				}
			}
			
			return heap;
		}
	}
}
