package kakaoBlindTest.recruitment2020;

public class Q01_1 {

    public int solution(String s) {
        int len = s.length();
        int answer = 9999;
        int compN = 0;

        for (int d = 1; d <= len; d++) {
            compN = func01(d, s);
            answer = Math.min(compN, answer);
        }

        return answer;
    }

    private int func01(int d, String s) {
        int result = 0;
        String str = s.substring(0,d);
        int cnt = 1;
        String compStr;

        if (d == s.length()) {
            return s.length();
        }


        for (int len = d; len <= s.length(); len += d) {
            if ( len + d > s.length()) {    // 비교하려는 대상의 길이가 짧아서 비교조차 못한다.
                if (cnt == 1) {
                    result = result + d + (s.length() - len);
                    break;
                } else {
                    result = result + Integer.toString(cnt).length() + d + (s.length() - len);
                    break;
                }
            }

            compStr = s.substring(len, len + d);    // 비교 대상

            if ( str.equals(compStr) ) {    // 같은 놈이다
                cnt++;
            } else {
                if (cnt == 1) {
                    result = result + d;
                } else {
                    result = result + Integer.toString(cnt).length() + d;
                }
                str = compStr;
                cnt = 1;
            }

        }

        return result;
    }
}
