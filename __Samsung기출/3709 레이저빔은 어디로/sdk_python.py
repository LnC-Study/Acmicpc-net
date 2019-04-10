MIRROR = -1
L, U, R, D = 0, 1, 2, 3
DIRECTIONS = [(0,-1), (1, 0), (0, 1), (-1, 0)]

class Task:
    def __init__(self, mirrors, razer_init_x, razer_init_y):
        self.direction = self.__get_init_direction(razer_init_x, razer_init_y)
        self.pos_x, self.pos_y = razer_init_x, razer_init_y
        self.__init_board(mirrors)

    @staticmethod
    def __get_init_direction(razer_init_x, razer_init_y):
        if razer_init_x == board_size + 1: return L
        if razer_init_x == 0: return R
        if razer_init_y == board_size + 1: return D
        if razer_init_y == 0: return U

    def __init_board(self, mirrors):
        self.board = [[set() for col in range(board_size + 1)] for row in range(board_size + 1)]
        for mirror in mirrors:
            self.board[mirror[1]][mirror[0]] = MIRROR

    def __is_mirror(self):
        return self.board[self.pos_y][self.pos_x] == MIRROR

    def __is_in(self):
        return 0 < self.pos_y <= board_size and 0 < self.pos_x <= board_size

    def __is_visited(self):
        return self.direction in self.board[self.pos_y][self.pos_x]

    def __next(self):
        self.pos_y, self.pos_x = self.pos_y + DIRECTIONS[self.direction][0], self.pos_x + DIRECTIONS[self.direction][1]
        if self.__is_in() and self.__is_mirror():
            self.direction = (self.direction + 1) % 4
            self.__next()

    def do(self):
        while True:
            self.__next()
            if not self.__is_in(): return (self.pos_x, self.pos_y)
            if self.__is_visited(): return (0, 0)

def data_in():
    N, R = map(int, input().split())
    mirrors = [tuple(map(int, input().split())) for _ in range(R)]
    razer_init_x, razer_init_y = map(int, input().split())
    return N, R, mirrors, razer_init_x, razer_init_y

def solution(mirrors, razer_init_x, razer_init_y):
    return Task(mirrors, razer_init_x, razer_init_y).do()

if __name__ == '__main__':
    global board_size

    test_case = int(input())
    for _ in range(test_case):
        board_size, _, mirrors, razer_init_x, razer_init_y = data_in()
        ans = solution(mirrors, razer_init_x, razer_init_y)

        print(ans[0], ans[1])