package programmers;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Q15 {
	private Set<HashSet<String>> combinations;
	
	public int solution(String[][] clothes) {
		int answer = 0;
		Map<String, Integer> map = new HashMap<String, Integer>();
		
		for (int idx = 0; idx < clothes.length; idx++)
			map.put(clothes[idx][1], map.getOrDefault(clothes[idx][1], 0) + 1);
		
		Set<HashSet<String>> comb = makeCombination(map.keySet());
		
		int num;
		for (HashSet<String> set : comb) {
			num = 1;
			for (String str : set)
				num *= map.get(str);
			answer += num;
		}
		/* remove the case of no camouflage */
		answer -= 1;
		
		return answer;
	}
	
	/* makeCombination(): the function to make the combination of clothes by using dfs */
	private Set<HashSet<String>> makeCombination(Set<String> set){
		combinations = new HashSet<HashSet<String>>();
		HashSet<String> comb = new HashSet<String>();
		String[] category = new String[set.size()];
		category = set.toArray(category);
		dfs(comb, category, 0);
		
		return combinations;
	}
	
	/* dfs(): the procedure to update combinations */
	private void dfs(HashSet<String> comb, String[] category, int idx) {
		if (idx == category.length)
			combinations.add(comb);
		else {
			HashSet<String> comb2 = new HashSet<String>(comb);
			comb.add(category[idx]);
			dfs(comb, category, idx + 1);
			dfs(comb2, category, idx + 1);	
		}
	}
}
