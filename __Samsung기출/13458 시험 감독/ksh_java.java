import java.util.*;

public class ksh_java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Long> ary = new ArrayList<>();

        for(;N>0; N--)
            ary.add(sc.nextLong());

        long B = sc.nextLong();
        long C = sc.nextLong();
        long result = 0;
        for(long people : ary) {
            if(people < B)
                result++;
            else
                result += (long) (Math.ceil((people - B) / (double)C)) + 1;
        }

        System.out.println(result);
    }
}

/*
* public class ksh_java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashMap<Long, Long> people_room = new HashMap<>();

        long people;
        for(;N>0; N--) {
            people = sc.nextLong();
            if (people_room.isEmpty()  //when it is first input
                    || !people_room.containsKey(people)) { //or have no pair
                people_room.put(people, 1L);
            } else { //when have same pair then update
                people_room.put(people,people_room.get(people)+1);
            }
        }

        long B = sc.nextLong();
        long C = sc.nextLong();
        long totalSupervisor = 0, subSup;
        for(long key : people_room.keySet()) {
            if(key < B)
                subSup = 0;
            else
                subSup = (long) (Math.ceil((double) (key - B) / (double) C));
            totalSupervisor += (1 + subSup) * people_room.get(key);
        }

        System.out.println(totalSupervisor);
    }
}
* */



