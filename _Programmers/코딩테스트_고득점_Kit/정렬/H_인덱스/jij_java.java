package programmers;

import java.util.Arrays;

class Q18 {
    public int solution(int[] citations) {
        int answer = 0, target;
        Arrays.sort(citations);
        for (int idx = 0; idx < citations.length; idx++) {
        	target = Math.min(citations[idx], citations.length - idx);
        	answer = Math.max(answer, target);
        }
        
        return answer;
    }
}