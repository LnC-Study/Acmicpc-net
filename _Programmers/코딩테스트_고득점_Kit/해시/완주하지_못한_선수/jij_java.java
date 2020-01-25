package programmers;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;


public class Q1 {

	public static void main(String[] args) {
		String[] test1_part = {"leo", "kiki", "eden"};
		String[] test2_part = {"marina", "josipa", "nikola", "vinko", "filipa"};
		String[] test3_part = {"mislav", "stanko", "mislav", "ana"};
		
		String[] test1_comp = {"eden", "kiki"};
		String[] test2_comp = {"marina", "josipa", "filipa", "nikola"};
		String[] test3_comp = {"mislav", "ana", "stanko"};
		
		System.out.println("test1: " + solution(test1_part, test1_comp));
		System.out.println("test2: " + solution(test2_part, test2_comp));
		System.out.println("test3: " + solution(test3_part, test3_comp));

	}

	public static String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> solMap = new HashMap<String, Integer>();
        
        if (!data_in(participant, solMap)) {
            System.out.println("some error occurs at data_in method");
            return "";
        }
        
        if (!handle_completion(completion, solMap)) {
            System.out.println("some error occurs at handle_completion method");
            return "";
        }
        
        /* keySet을 통한 Map 순회
        for (String remaining_participant : solMap.keySet())
            answer = remaining_participant;
        */
        
        /* entrySet()을 통한 Map 순회 */
        for (Entry<String, Integer> entry : solMap.entrySet())
        	answer = entry.getKey();
        
        
        return answer;
    }
    
    private static boolean data_in(String[] participant, Map<String, Integer> solMap) {
        try {
            for (String key : participant) {
                if (solMap.get(key) == null) solMap.put(key, 1);
                else solMap.replace(key, solMap.get(key), solMap.get(key) + 1);
            }    
        } catch (Exception e) {
            System.out.println(e);
            return false;
        }
        return true;
    }
    
    private static boolean handle_completion(String[] completion, Map<String, Integer> solMap) {
        try {
            for (String key : completion) {
                if (solMap.get(key) == 1) solMap.remove(key);
                else solMap.replace(key, solMap.get(key), solMap.get(key) - 1);
            }
        } catch (Exception e) {
            System.out.println(e);
            return false;
        }
        return true;
    }
}
