package kakaoBlindTest.recruitment2020;

public class Q03_3 {
    int hCnt = 0;

    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;
        if ( alreadyOpen(lock) )
            return true;

        countHomeCnt(lock);
        int[][] eL = expansionLock(lock, key.length);

        for (int cnt = 0; cnt < 4; cnt++) {
            if ( isOk(key, eL) ) {
                answer = true;
                break;
            } else {
                key = rotateKey(key);
            }
        }

        return answer;
    }

    private boolean alreadyOpen(int[][] lock) {
        for (int[] lA : lock) {
            for (int l : lA) {
                if (l == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private void countHomeCnt(int[][] lock) {
        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock.length; j++) {
                if( lock[i][j] == 0 ) {
                    hCnt++;
                }
            }
        }
    }


    private int[][] expansionLock(int[][] lock, int len) {
        int[][] eL = new int[lock.length + (len - 1) * 2][lock.length + (len - 1) * 2];

        for (int i = 0; i < eL.length; i++) {
            for (int j = 0; j < eL.length; j++) {
                eL[i][j] = 9;
            }
        }

        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock.length; j++) {
                eL[len - 1 + i][len - 1 + j] = lock[i][j];
            }
        }

        return eL;
    }


    private int[][] rotateKey(int[][] key) {
        int[][] rk = new int[key.length][key.length];

        for(int i = 0; i < key.length; i++) {       // (i,j) -> (j, (key.length - 1) - i)
            for (int j = 0; j < key.length; j++) {
                int ni = j;
                int nj = (key.length - 1) - i;
                rk[ni][nj] = key[i][j];
            }
        }

        return rk;
    }

    private boolean isOk(int[][] key, int[][] eL) {
        int fCnt = 0;

        boolean help = false;
        for (int i = 0; i < eL.length - (key.length - 1); i++) {
            for (int j = 0; j < eL.length - (key.length - 1); j++) {
                for (int kIdx = i; kIdx < key.length + i; kIdx++) {
                    help = false;
                    for (int kJdx = j; kJdx < key.length + j; kJdx++) {

                        if (eL[kIdx][kJdx] == 9) {
                            continue;
                        } else if (key[kIdx - i][kJdx - j] == 1 && eL[kIdx][kJdx] == 1) {
                            help = true;
                            break;
                        } else if (key[kIdx - i][kJdx - j] == 1 && eL[kIdx][kJdx] == 0) {
                            fCnt = fCnt + 1;
                        }
                    }

                    if (help) {
                        break;
                    }
                }

                if (fCnt == hCnt) {
                    return true;
                }
                fCnt = 0;
            }
        }

        return false;
    }

}
