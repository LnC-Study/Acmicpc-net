package programmers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import programmers.Q3.Solution;

public class Q4 {
	public static void main(String[] args) {
		final int COLS;
		final int ROWS;
		
		COLS = 3;
		ROWS = 5;
		
		int[] array = {1,5,2,6,3,7,4};
		int[][] commands = {{2, 5, 3},{4, 4, 1},{1, 7, 3}};
		int answer[];
		

		Q4 q4 = new Q4();
		Q4.Solution sol = q4.new Solution();
		
		answer = sol.solution(array, commands);
		
		for (int ans: answer) {
			System.out.println(ans);
		}
		System.out.println("------------");
		
		
	}
	
	class Solution {
	    public int[] solution(int[] array, int[][] commands) {
	        int[] answer = new int[commands.length];
	        List<Integer> list = new ArrayList<Integer>();
	        List<Integer> subList = new ArrayList<Integer>();
	        int count = 0;
	        
	        
	        for (int element : array)
	            list.add(element);
	        
	        
	  
	        
	        for (int col[] : commands) {
	            deep_copy(subList, list.subList(col[0] - 1, col[1]));
	            Collections.sort(subList);
	            answer[count] = subList.get(col[2] - 1);
	            count++;
	        }
	        
	        return answer;
	    }
	    
	    private List<Integer> deep_copy(List<Integer> destination, List<Integer> source) {
	    	destination.clear();
	    	for (Integer element : source)
	    		destination.add(new Integer(element));
	    	return destination;
	    }
	}
}
