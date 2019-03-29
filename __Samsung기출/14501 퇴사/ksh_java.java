import java.util.*;

public class ksh_java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] day = new int[N+1];
        int[] cost = new int[N+1];
        int[] max = new int[N+1];

        for(int i=1; i<=N; i++) {
            day[i] = sc.nextInt();
            cost[i] = sc.nextInt();
        }

        int nextday, todayCost;
        if(day[N] == 1)
            max[N] = cost[N];
        for(int i=N-1; i>0; i--) { //1 ~ N-1
            if(N-i+1 < day[i]) { //remained day < cost day
                max[i] = max[i + 1];
                continue;
            }
            todayCost = cost[i];
            nextday = i + day[i];
            if(nextday <= N)
                todayCost += max[nextday];
            max[i] = todayCost > max[i+1] ? todayCost : max[i+1];
        }

//        for(int m : max)
//            System.out.print(m + " ");
        System.out.println(max[1]);
    }
}