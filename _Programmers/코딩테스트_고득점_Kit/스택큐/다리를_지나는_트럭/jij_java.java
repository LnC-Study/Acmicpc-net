package programmers;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class Q6 {

	
	
	public static void main(String[] args) {
		int answer;
		
		int bridge_length = 2;
		int weight = 10;
		int[] truck_weights = {7, 4, 5, 6};

		Q6 q = new Q6();
		Q6.Solution sol = q.new Solution();

		answer = sol.solution(bridge_length, weight, truck_weights);
		
		System.out.println(answer);
	}

	class Solution {
		class Truck {
			int time;
			int weight;
			Truck(int weight) {
				time = 1;
				this.weight = weight;
			}
			
			boolean checkWeight(int total_weight, int weight) {
				return total_weight + this.weight <= weight;
			}
			
			boolean checkTime(int bridge_length) {
				return this.time > bridge_length;
			}
			
			void plusTime() {
				this.time++;
			}
			
			int plusWeight(int total_weight) {
				return total_weight + this.weight;
			}
			
			int minusWeight(int total_weight) {
				return total_weight - this.weight;
			}
		}
		
		public int solution(int bridge_length, int weight, int[] truck_weights) {
			int answer = 0;
			List<Truck> ready = new ArrayList<Truck>();
			List<Truck> passing = new ArrayList<Truck>();
			int total_weight = 0;
			
			for (int w : truck_weights) ready.add(new Truck(w));
			
			while (true) {
				if (ready.isEmpty() && passing.isEmpty()) break;
				
				for (Truck truck : passing) truck.plusTime(); 
				answer++;
				
				if (!passing.isEmpty() && passing.get(0).checkTime(bridge_length)) {
					total_weight = passing.get(0).minusWeight(total_weight);
					passing.remove(0);
				}
				
				if (!ready.isEmpty() && ready.get(0).checkWeight(total_weight, weight)) {
					total_weight = ready.get(0).plusWeight(total_weight);
					passing.add(ready.remove(0));
				}		
			}
			
			return answer;
		}
	}
}
