class FenwickTree:
    def __init__(self, _movies, _tasks):
        self.size, self.tree, self.movieIndex = _movies + _tasks, None, None
        self._initialize( _movies, _tasks)

    def update(self, _idx, _diff):
        while _idx <= self.size:
            self.tree[ _idx] += _diff
            _idx += (_idx & -_idx)

    def get_sum(self, _idx):
        sum = 0
        while _idx > 0:
            sum += self.tree[_idx]
            _idx -= (_idx & -_idx)
        return sum

    def _initialize(self, _movies, _tasks):
        self.tree, self.movieIndex = [0 for _ in range( self.size + 1)], \
                                     [idx + _tasks for idx in range(0, _movies + 1)]
        for number in range(1, _movies + 1):
            self.update( number + _tasks, 1)

    def get_movie_index(self, _movie):
        return self.movieIndex[ int(_movie)]

    def set_movie_index(self, _movie, _new):
        self.movieIndex[ int(_movie)] = _new

def data_in():
    movies, tasks = map( int, input().split())
    return movies, tasks, input().split()

def solution( movies, tasks, taskList):
    fenwickTree = FenwickTree( movies, tasks)
    nextIdx = tasks
    for task in taskList:
        pos = fenwickTree.get_movie_index( task)
        print(fenwickTree.get_sum( pos) - 1, end = ' ')
        fenwickTree.update( pos, -1)
        fenwickTree.set_movie_index(task, nextIdx)
        fenwickTree.update( nextIdx, 1)
        nextIdx -= 1
    print()

if __name__ == '__main__':
    testCase = int(input())
    for _ in range( testCase):
        movies, tasks, taskList = data_in()
        solution( movies, tasks, taskList)