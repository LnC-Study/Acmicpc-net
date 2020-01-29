package programmers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Q17 {
	class Job {
		int inTime;
		int runningTime;

		Job(int inTime, int runningTime) {
			this.inTime = inTime;
			this.runningTime = runningTime;
		}

		public int getTerminatedTime(int startTime) {
			return startTime - inTime + runningTime;
		}
	}

	public int solution(int[][] jobs) {
		int answer = 0, time = 0, idx = 0;
		List<Job> list = new ArrayList<Job>();
		List<Integer> terminatedTime = new ArrayList<Integer>();

		for (int[] job : jobs)
			list.add(new Job(job[0], job[1]));

		Collections.sort(list, new Comparator<Job>() {
			@Override
			public int compare(Job j1, Job j2) {
				return j1.inTime - j2.inTime;
			}
		});

		PriorityQueue<Job> pq = new PriorityQueue<Job>(new Comparator<Job>() {
			@Override
			public int compare(Job j1, Job j2) {
				return j1.runningTime - j2.runningTime;
			}
		});

		while (terminatedTime.size() != jobs.length) {
			/* append job in the ready queue */
			while (!list.isEmpty() && list.get(0).inTime <= time) {
				pq.add(list.get(0));
				list.remove(0);
			}
			/* select and run */
			if (!pq.isEmpty()) {
				terminatedTime.add(pq.peek().getTerminatedTime(time));
				time += pq.peek().runningTime;
				pq.poll();
			} else
				time++;
		}

		for (Integer item : terminatedTime)
			answer += item;

		return answer / terminatedTime.size();
	}
}
