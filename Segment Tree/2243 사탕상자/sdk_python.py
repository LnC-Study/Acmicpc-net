class FenwickTree:
    def __init__(self):
        self.size = 1000000
        self.tree = [0 for _ in range( self.size + 1)]

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

    def get_candy(self, _pick):
        left, right = 1, self.size
        while left < right:
            mid = int( (left + right) / 2)
            cumCandies = self.get_sum( mid)
            if cumCandies >= _pick: right = mid
            else: left = mid + 1

        return left

def data_in():
    N = int(input())
    return N, [ input().split() for _ in range( N)]

def solution( N, cmds):
    fenwickTree = FenwickTree()
    for cmd in cmds:
        if cmd[0] == '2': # insert
            fenwickTree.update( int( cmd[1]), int( cmd[2]))
        else: # pick
            pick = int( cmd[1])
            candy = fenwickTree.get_candy( pick)
            print( candy)
            fenwickTree.update( candy, -1)

if __name__ == '__main__':
    N, cmds = data_in()
    solution( N, cmds)