package kakaoBlindTest.recruitment2020;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Collections;

public class Q05_2 {      // 기둥과 보 설치

    Set<Material> result = new HashSet();

    class Material implements Comparable<Material> {
        int x, y, kind;

        Material(int x, int y, int kind) {
            this.x = x;
            this.y = y;
            this.kind = kind;
        }

        @Override
        public int hashCode() {
            int c = 31;
            int result = Integer.hashCode(this.x);
            result = c * result + Integer.hashCode(this.y);
            result = c * result + Integer.hashCode(this.kind);
            result = c * result + result;
            return result;
        }

        @Override
        public boolean equals(Object o) {
            if ( !(o instanceof Material)) {
                return false;
            }

            Material m = (Material) o;
            return this.x == m.x && this.y == m.y && this.kind == m.kind;
        }

        @Override
        public int compareTo(Material o) {
            return (this.x - o.x) == 0
                    ? (this.y - o.y) == 0 ? (this.kind - o.kind) : (this.y - o.y)
                    : (this.x - o.x);
        }
    }

    public int[][] solution(int n, int[][] build_frame){
        getResult(n, build_frame);              // result 산출
        List<Material> list = sortResult();     // result 소팅
        int[][] answer = parseArray(list);      // List -> Array
        return answer;
    }


    private void getResult(int n, int[][] build_frame){
        for (int[] bf : build_frame) {
            Material item = new Material(bf[0], bf[1], bf[2]);

            if (bf[3] == 1) {               // 등록
                result.add(item);
                if ( !isOk() ) {            // 등록한게 이상하면
                    result.remove(item);        // 넣은거 다시 제거
                }
            } else {                        // 제거
                result.remove(item);
                if ( !isOk() ) {            // 제거한게 이상하면
                    result.add(item);           // 제거한거 다시 추가
                }
            }
        }
    }


    private boolean isOk(){
        boolean flag = true;
        int x, y;

        for (Material m : result ) {
            x = m.x;
            y = m.y;

            if (m.kind == 0) {    // 기둥
                flag = (y == 0)                                                   // 바닥 위 일 때
                        || result.contains(new Material(x, y-1, 0))       // 기둥 위일 때
                        || result.contains(new Material(x-1, y, 1))       // 보 오른쪽 위일 때
                        || result.contains(new Material(x, y, 1));           // 보 왼쪽 위일 떄
            } else {  // 보
                flag = result.contains(new Material(x, y-1, 0))           // 기둥 위일 때
                        || result.contains(new Material(x+1, y-1, 0))  // 기둥 위일 때
                        || (result.contains(new Material(x-1, y, 1))      // 양쪽이 보일 때
                            && result.contains(new Material(x+1, y, 1)));
            }

            if ( flag == false ) {
                break;
            }
        }

        return flag;
    }


    private List<Material> sortResult(){
        List<Material> list = new ArrayList<>(result);
        Collections.sort(list);
        return list;
    }


    private int[][] parseArray(List<Material> list){
        int[][] answer = new int[list.size()][3];
        for (int idx = 0; idx < list.size(); idx++) {
            int[] a = {list.get(idx).x, list.get(idx).y, list.get(idx).kind};
            answer[idx] = a;
        }
        return answer;
    }
}
