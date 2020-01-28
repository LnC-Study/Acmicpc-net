package programmers;

import java.util.HashMap;
import java.util.Map;

public class Q15_1 {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < clothes.length; i++)
        	map.put(clothes[i][1], map.getOrDefault(clothes[i][1], 0) + 1);
        for (int value : map.values())
        	answer *= (value + 1);
        /* remove the case of no camouflage */
        answer -= 1;

        return answer;
    }
}
