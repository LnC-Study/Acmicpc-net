package programmers;

import java.util.Map;
import java.util.HashMap;

public class Q5 {

	public static void main(String[] args) {
		Q5 q5 = new Q5();
		Q5.Solution sol = q5.new Solution();
		boolean ans;
		String[] phone_book = { "119", "97674223", "1195524421" };

		ans = sol.solution(phone_book);

		System.out.println(ans);

		String[] phone_book2 = { "123", "456", "789" };
		ans = sol.solution(phone_book2);
		System.out.println(ans);

	}

	class Solution {
		class Page {
			Map<String, Page> page;

			public Page(Map<String, Page> page) {
				this.page = page;
			}
		}

		public boolean solution(String[] phone_book) {
			boolean answer = true;
			Map<String, Page> book = new HashMap<String, Page>();
			Page current = null;
			boolean isFirstPage;
			String number;
			boolean flag;

			for (String phone_number : phone_book) {
				isFirstPage = true;
				flag = true;
				for (int idx = 0; idx < phone_number.length(); idx++) {
					number = phone_number.substring(idx, idx + 1);

					if (isFirstPage) {
						if (!book.containsKey(number)) {
							book.put(number, new Page(new HashMap<String, Page>()));
							flag = false;
						}
						current = book.get(number);
						isFirstPage = false;
					}

					else {
						if (!current.page.containsKey(number)) {
							if (current.page.isEmpty() && flag) {
								answer = false;
								break;
							}
							flag = false;
							current.page.put(number, new Page(new HashMap<String, Page>()));
						}
						current = current.page.get(number);

					}

					if (idx == phone_number.length() - 1 && !current.page.isEmpty()) {
						answer = false;
					}

				}
				if (!answer)
					break;
			}

			return answer;
		}
	}
}
