INF = 999999999999

class Point:
    def __init__(self, _coordinate):
        self.x, self.y = int( _coordinate[0]), int( _coordinate[1])
    def __gt__(self, other):
        if self.x == other.x:
            return True if self.y > other.y else False
        else:
            return True if self.x > other.x else False

def data_in():
    numOfSpots = int(input())
    return numOfSpots, [ Point(input().split()) for _ in range( numOfSpots)]

def get_distance( _spotA, _spotB):
    return ( _spotB.x - _spotA.x) * ( _spotB.x - _spotA.x) + \
           ( _spotB.y - _spotA.y) * ( _spotB.y - _spotA.y)

def merge_two_sections( _sortedSpots, _left, _mid, _right, _minLength):
    for leftIdx in range( _mid-1, _left-1, -1):
        if pow( _sortedSpots[leftIdx].x - _sortedSpots[_mid].x, 2) >= _minLength:
            break

        for rightIdx in range( _mid, _right + 1):
            if pow( _sortedSpots[rightIdx].x - _sortedSpots[leftIdx].x, 2) >= _minLength:
                break
            _minLength = min( _minLength, get_distance( _sortedSpots[leftIdx], _sortedSpots[rightIdx]))

    return _minLength

def devide_N_Conquer( _sortedSpots, _left, _right, _minLength):
    if _left >= _right: return INF
    if _right - _left == 1:
        return get_distance(_sortedSpots[_left], _sortedSpots[_right])

    mid = int((_right + _left) / 2)
    distanceLeft, distanceRight = devide_N_Conquer( _sortedSpots, _left, mid-1, _minLength), \
                                  devide_N_Conquer( _sortedSpots, mid, _right, _minLength)
    _minLength = min( _minLength, min( distanceLeft, distanceRight))

    return merge_two_sections( _sortedSpots, _left, mid, _right, _minLength)

def solution( _numOfSpots, _sortedSpots):
    return devide_N_Conquer( _sortedSpots, 0, _numOfSpots -1, INF)

if __name__ == '__main__':
    numOfSpots, spots = data_in()
    print( solution( numOfSpots, sorted( spots)))