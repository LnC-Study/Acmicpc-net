package kakaoBlindTest.recruitment2020;

import java.util.*;

public class Q07 {

    Map<Location, Integer> map = new HashMap<>();
    List<Location> queue = new ArrayList<>();
    Set<Location> visited = new HashSet<>();
    int[][] field;
    int answer = 0;

    class Location {
        int x1, y1, x2, y2;

        Location(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        @Override
        public int hashCode() {
            int c = 31;
            int result = Integer.hashCode(this.x1);
            result = c * result + Integer.hashCode(this.y1);
            result = c * result + Integer.hashCode(this.x2);
            result = c * result + Integer.hashCode(this.y2);
            result = c * result + result;
            return result;
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Location)) {
                return false;
            }

            Location location = (Location) o;
            return (this.x1 == location.x1) && (this.y1 == location.y1)
                    && (this.x2 == location.x2) && (this.y2 == location.y2);
        }

        @Override
        public String toString() {
            return "    [ x1: " + x1 + ", y1: " + y1 + ", x2: " + x2 + ", y2: " + y2 + "]";
        }
    }

    public int solution(int[][] board) {
        field = board;
        Location location = new Location(0, 0, 1, 0);
        queue.add(location);
        map.put(location, 0);
        bfs();

        return answer;
    }

    private void bfs() {
        if (queue.isEmpty()) {
            return;
        }
        Location location = queue.remove(0);
        visited.add(location);

        if (isEndPoint(location)) {
            answer = map.get(location);
            return;
        } else {
            goLeft(location);
            goRight(location);
            goUp(location);
            goDown(location);
            turnLeftDown(location);
            turnLeftUp(location);
            turnRightDown(location);
            turnRightUp(location);
            bfs();
        }
    }


    private boolean isEndPoint(Location location) {
        int n = field.length;
        if ( (location.x1 == (n - 1) && location.y1 == (n - 1)) || (location.x2 == (n - 1) && location.y2 == (n - 1))) {
            return true;
        } else {
            return false;
        }
    }


    private void goLeft(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if ( y1 == y2 ) {
            if ((x1 - 1) >= 0 && field[y1][x1 - 1] == 0) {
                moved.x1 = x1 - 1;
                moved.x2 = x2 - 1;
            } else {
                return;
            }
        } else {
            if ((x1 - 1) >= 0 && field[y1][x1 - 1] == 0 && field[y2][x2 - 1] == 0) {
                moved.x1 = x1 - 1;
                moved.x2 = x2 - 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void goRight(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if ( y1 == y2 ) {
            if ((x2 + 1) < field.length && field[y2][x2 + 1] == 0) {
                moved.x1 = x1 + 1;
                moved.x2 = x2 + 1;
            } else {
                return;
            }
        } else {
            if ((x2 + 1) < field.length && field[y2][x2 + 1] == 0 && field[y1][x1 + 1] == 0) {
                moved.x1 = x1 + 1;
                moved.x2 = x2 + 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void goUp(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if ( y1 == y2 ) {
            if (((y1 - 1) >= 0 && field[y1 - 1][x1] == 0) && ((y2 - 1) >= 0 && field[y2 - 1][x2] == 0)) {
                moved.y1 = y1 - 1;
                moved.y2 = y2 - 1;
            } else {
                return;
            }
        } else {
            if ((y1 - 1) >= 0 && field[y1 - 1][x1] == 0) {
                moved.y1 = y1 - 1;
                moved.y2 = y2 - 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void goDown(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if ( y1 == y2 ) {
            if (((y1 + 1) < field.length && field[y1 + 1][x1] == 0) && ((y2 + 1) < field.length && field[y2 + 1][x2] == 0)) {
                moved.y1 = y1 + 1;
                moved.y2 = y2 + 1;
            } else {
                return;
            }
        } else {
            if ((y2 + 1) < field.length && field[y2 + 1][x2] == 0) {
                moved.y1 = y1 + 1;
                moved.y2 = y2 + 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void turnLeftUp(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if (y1 == y2) {
            if ((y1 - 1) >= 0 && field[y1 - 1][x1] == 0 && field[y2 - 1][x2] == 0) {
                moved.y1 = y1 - 1;
                moved.x2 = x2 - 1;
            } else {
                return;
            }
        } else {
            if ((x1 - 1) >= 0 && field[y1][x1 - 1] == 0 && field[y2][x2 - 1] == 0) {
                moved.x1 = x1 - 1;
                moved.y2 = y2 - 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void turnRightUp(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if (y1 == y2) {
            if (((y1 - 1) >= 0 && field[y1 - 1][x1] == 0) && ((y2 - 1) >= 0 && field[y2 - 1][x2] == 0)) {
                moved.x1 = x1 + 1;
                moved.y1 = y1 - 1;
            } else {
                return;
            }
        } else {
            if ((x2 + 1) < field.length && field[y2][x2 + 1] == 0 && field[y1][x1 + 1] == 0) {
                moved.x2 = x2 + 1;
                moved.y2 = y2 - 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void turnLeftDown(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if (y1 == y2) {
            if (((y1 + 1) < field.length && field[y1 + 1][x1] == 0) && ((y2 + 1) < field.length && field[y2 + 1][x2] == 0)) {
                moved.x2 = x2 - 1;
                moved.y2 = y2 + 1;
            } else {
                return;
            }
        } else {
            if ((x1 - 1) >= 0 && field[y1][x1 - 1] == 0 && field[y2][x2 - 1] == 0) {
                moved.x1 = x1 - 1;
                moved.y1 = y1 + 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void turnRightDown(Location location) {
        int x1 = location.x1;
        int y1 = location.y1;
        int x2 = location.x2;
        int y2 = location.y2;
        int time = map.get(location);
        Location moved = new Location(x1, y1, x2, y2);

        if (y1 == y2) {
            if (((y1 + 1) < field.length && field[y1 + 1][x1] == 0) && ((y2 + 1) < field.length && field[y2 + 1][x2] == 0)) {
                moved.x1 = x1 + 1;
                moved.y2 = y2 + 1;
            } else {
                return;
            }
        } else {
            if ((x2 + 1) < field.length && field[y2][x2 + 1] == 0 && field[y1][x1 + 1] == 0) {
                moved.x2 = x2 + 1;
                moved.y1 = y1 + 1;
            } else {
                return;
            }
        }

        pushQueue(moved, time);
    }


    private void pushQueue(Location moved, int time) {
        if (visited.contains(moved) || queue.contains(moved)) {
            return;
        } else {
            queue.add(moved);
            map.put(moved, time + 1);
        }
    }
}
