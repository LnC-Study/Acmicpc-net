package kakaoBlindTest.recruitment2020;

import java.util.ArrayList;
import java.util.List;

public class Q02 {      // 괄호 변환
    public String solution(String p) {
        String answer = genStr(p);
        return answer;
    }

    private String genStr(String s) {
        if ( s.isEmpty()) {
            return s;
        }
        String w = s;
        int idx = getIdx(w);
        String u = w.substring(0,idx);              // u >> 균형잡힌
        String v = w.substring(idx, w.length());

        if ( isValid(u) ) {
            w = u.concat(genStr(v));
        } else {
            w = "(".concat(genStr(v)).concat(")").concat(getReU(u));
        }

        return w;
    }

    private String getReU(String u) {
        String reU = u.substring(1,u.length() - 1);
        if (reU.isEmpty()) {
            return reU;
        } else {
            return reflect(reU);
        }
    }

    private String reflect(String reU) {
        String refU = "";
        for ( String s : reU.split("") ) {
            refU = refU.concat(s.equals("(") ? ")" : "(");
        }

        return refU;
    }

    private boolean isValid(String u) {
        boolean flag;
        List<String> stack = new ArrayList<>();
        String[] sArr = u.split("");

        for (String s : sArr) {
            if ( s.equals("(") ) {
                stack.add(s);
            } else {
                if (stack.isEmpty()) {
                    return false;
                } else if ( stack.get(stack.size()-1).equals("(") ) {
                    stack.remove(stack.size() - 1);
                } else {
                    stack.add(s);
                }
            }
        }

        if ( stack.isEmpty() ) {
            flag = true;
        } else {
            flag = false;
        }

        return flag;
    }


    private int getIdx(String s) {
        int result = 0;
        int cnt = 0;
        String[] sArr = s.split("");
        for (int idx = 0; idx < sArr.length; idx++) {
            if (sArr[idx].equals("(")) {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt == 0) {
                result = idx + 1;
                break;
            }
        }
        return result;
    }
}
