package programmers;

import java.util.HashSet;

public class Q19 {
	public int solution(String numbers) {
		int answer = 0;
		HashSet<Integer> set = new HashSet<>();
		permutation("", numbers, set);
		for (Integer number : set) {
			if (isPrime(number))
				answer++;
		}

		return answer;
	}

	public boolean isPrime(int n) {
		if (n == 0 || n == 1)
			return false;
		if (n == 2)
			return true;
		if (n % 2 == 0)
			return false;
		for (int i = 3; i <= (int) Math.sqrt(n); i += 2) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

	public void permutation(String prefix, String str, HashSet<Integer> set) {
		int n = str.length();
		if (!prefix.equals(""))
			set.add(Integer.valueOf(prefix));
		for (int i = 0; i < n; i++)
			permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i + 1, n), set);
	}
}
