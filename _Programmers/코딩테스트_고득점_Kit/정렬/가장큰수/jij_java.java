package programmers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Stream;
import java.util.Comparator;

public class Q8_1 {
	public static void main(String[] args) {
		String answer;
		int[] numbers1 = { 0, 0, 0, 0, 0, 0 };
		int[] numbers2 = { 3, 30, 34, 5, 9 };

		Q8_1 q = new Q8_1();
		Q8_1.Solution sol = q.new Solution();

		answer = sol.solution(numbers1);
		System.out.println(answer);

		answer = sol.solution(numbers2);
		System.out.println(answer);
	}

	class Solution {
		public String solution(int[] numbers) {
			String answer = "";
			List<Integer> list = new ArrayList<Integer>();

			for (int number : numbers)
				list.add(number);

			Iterator<Integer> iter = list.stream().sorted((n1, n2) -> {
				int n1n2 = Integer.parseInt(n1.toString() + n2.toString());
				int n2n1 = Integer.parseInt(n2.toString() + n1.toString());

				if (n1n2 == n2n1)
					return 0;
				if (n1n2 > n2n1)
					return -1;
				else
					return 1;
			}).iterator();

			
			
			while (iter.hasNext())
				answer += iter.next().toString();

			return Integer.toString(Integer.parseInt(answer));
		}
	}
}
