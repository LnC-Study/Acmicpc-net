DIRS = [(0, 1), (-1, 0), (0, -1), (1, 0)]
RU, RD, LD, LU = (-1,0), (0,0), (0,-1), (-1,-1)
BORDERS, SIZE = [ RU, RD, LD, LU], 100
boxes = None

class Box :
    def __init__(self):
        self.state = { RU: False, RD: False, LD: False, LU: False}

    def is_filled(self):
        return self.state[RU] and self.state[RD] and self.state[LD] and self.state[LU]

class Curve :
    def __init__(self, start_pos, direction):
        self.start_pos, self.direction, self.road = start_pos, direction, [ direction]

    def next_gen(self):
        rev = list(self.road)
        rev.reverse()
        for idx in range(len(rev)): rev[idx] = (rev[idx] + 1) % 4
        self.road.extend(rev)

    @staticmethod
    def is_in( row, col):
        return 0 <= row < SIZE and 0 <= col < SIZE

    def _dotting(self, pos):
        global boxes

        for idx, border_dir in enumerate( BORDERS):
            row, col = pos[0] + border_dir[0], pos[1] + border_dir[1]
            if self.is_in( row, col):
                matched_dir = BORDERS[ (idx + 2) % 4]
                boxes[ row][ col].state[ matched_dir] = True

    def draw(self):
        cur = self.start_pos
        self._dotting(cur)
        for step in self.road :
            next = (cur[0] + DIRS[step][1], cur[1] + DIRS[step][0])
            cur = next
            self._dotting(cur)

def data_in():
    curves = int(input())
    return curves, [ tuple( map(int, input().split())) for _ in range( curves)]

def init_boxes():
    return [[ Box() for _ in range( SIZE)] for __ in range(SIZE)]

def get_dragon_curves():
    ans = 0
    for row in range( SIZE):
        for col in range( SIZE):
            if boxes[ row][col].is_filled(): ans += 1

    return ans

def solution( cmds):
    global boxes

    boxes = init_boxes()
    for cmd in cmds:
        start_row, start_col, direction, generations = cmd

        current = Curve( (start_row, start_col), direction)
        for _ in range( generations): current.next_gen()
        current.draw()

    return get_dragon_curves()

if __name__ == '__main__':
    _, cmds = data_in()
    ans = solution( cmds)
    print( ans)