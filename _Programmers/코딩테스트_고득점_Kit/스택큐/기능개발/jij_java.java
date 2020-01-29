package programmers;

import java.util.ArrayList;
import java.util.List;

public class Q16 {
	public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> terminated = new ArrayList<Integer>();
        int target = 0, day = 0, num = 0;
        while (target < progresses.length) {
            num = 0;
            while (target < progresses.length && progresses[target] + (speeds[target] * day) >= 100) {
                num++;
                target++;
            }
            if (num != 0)
                terminated.add(num);
            day++;
        }
        int[] answer = new int[terminated.size()];
        for (int idx = 0; idx < terminated.size(); idx++)
            answer[idx] = terminated.get(idx);
        return answer;
    }
}
