package programmers;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class Q11 {
	public int solution(int N, int number) {
        int answer = 0;
        Operation operation = new Operation(N, number);
        answer = operation.findOptimizedSol(1);
        return answer;
    }
	
	class Operation {
		private int N;
		private int number;
		private Map<Integer, TreeSet<Integer>> memoization; 
		
		Operation (int N, int number) {
			this.N = N;
			this.number = number;
			this.memoization = new HashMap<Integer, TreeSet<Integer>>();
		}
		
		public int findOptimizedSol(int amount) {
			TreeSet<Integer> item = new TreeSet<Integer>();
			item.add(concatenate(amount));
			int result = -1;
			
			for (int idx = 1; idx < amount; idx++) {
				for (int left : memoization.get(idx)) {
					for (int right : memoization.get(amount - idx)) {
						if(!item.contains(left + right))
							item.add(left + right);
						if(!item.contains(left - right))
							item.add(left - right);
						if(!item.contains(left * right))
							item.add(left * right);
						if((right != 0) && !item.contains(left / right))
							item.add(left / right);
					}
				}
			}
			
			if (item.contains(number))
				return amount;
			memoization.put(amount, item);
			if (amount < 9)
				result = findOptimizedSol(++amount);
			
			return result;
		}
		
		private int concatenate(int amount) {
			String concatN = "";
			for (int count = 0; count < amount; count++)
				concatN += Integer.toString(N);
			return Integer.parseInt(concatN);
		}
	}
}
