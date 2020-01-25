package programmers;

import java.util.Arrays;

class Q10 {
	public int solution(int n, int[] lost, int[] reserve) {
		int answer = n;
		int[] suit = new int[n];
		Arrays.fill(suit, 1);

		for (int r : reserve)
			suit[r - 1]++;

		for (int l : lost) {
			suit[l - 1]--;
			if (suit[l - 1] >= 1)
				continue;
			if (l - 2 >= 0) {
				if (hasReserve(suit, l - 2)) {
					borrowSuit(suit, l - 1, l - 2);
					continue;
				}
			}
			if (l < n) {
				if (hasReserve(suit, l)) {
					borrowSuit(suit, l - 1, l);
					continue;
				}
			}
			answer--;
		}

		return answer;
	}

	private boolean hasReserve(int[] suit, int idx) {
		return suit[idx] >= 2;
	}

	private int[] borrowSuit(int[] suit, int borrower, int lender) {
		suit[lender]--;
		suit[borrower]++;
		return suit;
	}
}