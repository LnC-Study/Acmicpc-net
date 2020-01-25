package programmers;

import java.util.Stack;

public class Q2 {
	
	public static void main(String[] args) {
		int[] input = {3,9,9,3,5,7,2};
		
		int[] result = solution(input);
		
		
		/*
		for (int n : result) {
			System.out.println(n);
		}
		*/
		
		System.out.println("--------------------");
		
		int[] input2 = {1,5,3,6,7,6,5};
		
		int[] result2 = solution(input2);
		/*
		for (int n : result2) {
			System.out.println(n);
		}
		*/
		
	}

	
	public static int[] solution(int[] heights) {
		int[] answer = new int[heights.length];
		Stack<Integer> stack = new Stack<Integer>();

		for (int h : heights)
			stack.push(h);

		System.out.println(stack.size());
		
		while (stack.empty()) {
			int target = stack.pop();
			for (int i = stack.size() - 1; i >= 0; i--) {
				if (stack.get(i) > target) {
					answer[stack.size()] = i + 1;
					break;
				}
				if (i == 0)
					answer[stack.size()] = 9;
			}
		}
		
		/*
		for (int n : answer) {
			System.out.println(n);
		}
		*/
		

		return answer;
	}
}
