package programmers;

import java.util.Arrays;

public class Q13_2 {
	public int solution(int[] budgets, int M) {
		Arrays.sort(budgets);
		int min = 0;
		int max = budgets[budgets.length - 1];
		int mean, optimal = 0;
		long total = sum(budgets, max);
		
		if (total <= M)
			return max;
		while (min <= max) {
			mean = (min + max) / 2;
			total = sum(budgets, mean);
			if (total == M)
				return mean;
			else if (total > M)
				max = mean - 1;
			else {
				optimal = mean;
				min = mean + 1;
			}
		}
		
		return optimal;
	}
	
	private long sum(int[] numbers, int limit) {
		long result = 0L;
		for (int number : numbers)
			result += number <= limit ? number : limit;
		return result;
	}
}
