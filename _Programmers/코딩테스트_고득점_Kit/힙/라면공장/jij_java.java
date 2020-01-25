package programmers;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Q7 {
	
	public static void main(String[] args) {
		int answer;
		int stock = 4;
		int[] dates = {4, 10, 15};
		int[] supplies = {20, 5, 10};
		int k = 30;

		Q7 q = new Q7();
		Q7.Solution sol = q.new Solution();

		answer = sol.solution(stock, dates, supplies, k);
		System.out.println(answer);
	}
	
	class Stock {
		private int date;
		private int stock;
		
		Stock(int date, int amount) {
			this.date = date;
			this.stock = amount;
		}
		
		public boolean isEmpty() {
			return stock <= 0; 
		}
		
		public void supplyStock(int amount) {
			stock = stock + amount;
		}
		
		public void updateStock(int today) {
			stock = stock - (today - date);
			date = today;
		}
		
		public boolean checkEndDay(int endDate) {
			return (stock >= 0) && (date == endDate);
		}
	}
	
	class StockManager {
		private int[] dates;
		private int[] supplies;
		private int endDate;
		private Queue<Integer> balances;
		
		StockManager(int[] dates, int[] supplies, int endDate) {
			this.dates = dates;
			this.supplies = supplies;
			this.endDate = endDate;
			this.balances = new PriorityQueue<Integer>(Comparator.reverseOrder()); 
		}
		
		public int findOptimizedPlan(int initialStock) {
			Stock stock = new Stock(0, initialStock);
			int timesOfSupply = 0;
			
			for (int idx = 0; idx <= dates.length; idx++) {
				if (idx == dates.length) {
					stock.updateStock(endDate);
				} else {
					stock.updateStock(dates[idx]);
					balances.add(supplies[idx]);
				}
				
				while (stock.isEmpty()) {
					if (stock.checkEndDay(endDate))
						break;
					stock.supplyStock(balances.poll());
					timesOfSupply++;
				}
			}
				
			return timesOfSupply;
		}
	}

	class Solution {
		public int solution(int stock, int[] dates, int[] supplies, int k) {
			int answer = 0;
			StockManager stockManager = new StockManager(dates, supplies, k);
			answer = stockManager.findOptimizedPlan(stock);
			return answer;
		}	
	}
}














