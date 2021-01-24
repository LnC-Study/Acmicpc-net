package kakaoBlindTest.recruitment2020;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Arrays;

public class Q06_2 {        // 16:15 ~

    int answer = -1;
    int len;
    int totMember;

    List<List<Integer>> listDist = new ArrayList<>();

    public int solution(int n, int[] weak, int[] dist) {
        if ( weak.length == 0) {
            return 0;
        }

        // 0. 변수 세팅
        len = n;
        totMember = dist.length;
        Set<Integer> setWeak = new HashSet<>();
        Arrays.stream(weak).forEach(i -> setWeak.add(i));

        // 1. dist 경우의 수 나열
        getListDist(dist);

        // 2. weak 포인트들 시작점 순회
        for (int idx = 0; idx < weak.length; idx++) {
            for (List<Integer> item : listDist) {
                func01(weak[idx], item, new HashSet<>(setWeak));
            }
        }


        return answer;
    }

    private void getListDist(int[] dist) {
        List<Integer> source = new ArrayList<>();
        List<Integer> target = new ArrayList<>();
        for (int i : dist) {
            source.add(i);
        }
        permutate(source, target);
    }

    private void permutate(List<Integer> source, List<Integer> target) {
        if (source.isEmpty()) {
            listDist.add(target);
            return;
        } else {
            for (int idx = 0; idx < source.size(); idx++) {
                Integer temp = source.remove(idx);
                target.add(temp);

                permutate(source, new ArrayList<>(target));

                source.add(idx, temp);
                target.remove(target.size() - 1);
            }
        }
    }

    private void func01(int idxStart, List<Integer> dist, Set<Integer> setWeak) {
        if (setWeak.isEmpty()) {
            answer = answer == -1
                    ? (totMember - dist.size())
                    : answer < (totMember - dist.size()) ? answer : (totMember - dist.size());
            return;
        } else if (dist.isEmpty()) {
            answer = answer == -1 ? -1 : answer;
            return;
        } else {
            List<Integer> copyDist = new ArrayList<>(dist);
            int distance = copyDist.remove(0);
            for (int idx = 0; idx <= distance; idx++) {
                idxStart = (idxStart) % len;
                if (setWeak.contains(idxStart)) {
                    setWeak.remove(idxStart);
                }
                idxStart++;
            }

            idxStart = getIdxStart(idxStart, setWeak);
            func01(idxStart, copyDist, new HashSet<>(setWeak));
        }
    }

    private int getIdxStart(int idxStart, Set<Integer> setWeak) {
        int idxNext = idxStart + 1;
        if (setWeak.isEmpty()) {
            return idxNext;
        } else {
            while (true) {
                if (setWeak.contains(idxNext)) {
                    return idxNext;
                } else {
                    idxNext = (idxNext + 1) % len;
                }
            }
        }
    }
}
