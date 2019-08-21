
import java.util.*;

public class ksh_java {
    static ArrayList<ArrayList<Integer>> singers = new ArrayList<>();
    static LinkedList<Integer> queue = new LinkedList<>();
    static ArrayList<Integer> haveHowManyBefores = new ArrayList<>();
    static ArrayList<Integer> result = new ArrayList<>();
    static int len = 0;

    public static void main (String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); //number of singers
        int m = scanner.nextInt(); //number of sub PDs
        int number, before, current;

        //initialization
        for (int i = 0; i <= n; i++) {
            ArrayList<Integer> arry = new ArrayList<>();
            singers.add(arry);
            haveHowManyBefores.add(0);
        }

        while (m-- > 0) { //input for 'm'
            number = scanner.nextInt(); //number of inputs
            before = scanner.nextInt();
            for (int i = 1; i < number; i++) {
                current = scanner.nextInt();
                singers.get(before).add(current);//add current into singers[before]
                haveHowManyBefores.set(current, haveHowManyBefores.get(current) + 1);
                before = current;
            }
        }

        //set start point : which have no befores
        for (int i = n; i >= 1; i--)
            if (haveHowManyBefores.get(i) == 0)
                queue.add(i);

        while (!queue.isEmpty()) {
            current = queue.pop();
            if (haveHowManyBefores.get(current) == 0)
                result.add(current);

            for (int i : singers.get(current)) {
                haveHowManyBefores.set(i, haveHowManyBefores.get(i) - 1);
                if (haveHowManyBefores.get(i) == 0)
                    queue.add(i);
            }
        }


        if (result.size() == n) {
            for (int i = 0; i < n; i++)
                System.out.println(result.get(i));
        } else
            System.out.println("0");

    }
}