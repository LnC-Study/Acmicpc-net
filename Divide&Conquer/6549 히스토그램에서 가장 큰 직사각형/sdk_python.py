class Node:
    def __init__(self, _index, _left, _right):
        self.index, self.left, self. right = _index, _left, _right
        self.leftChild, self.rightChild = None, None

class SegmentTree:
    def __init__(self, _rectangles):
        self.rectangles = _rectangles
        self.head = self.create(0, len( _rectangles) - 1)

    def create(self, _left, _right):
        if _left == _right: return Node( _left, _left, _left)
        newNode = Node( None, _left, _right)

        mid = int( (_left + _right) / 2)
        newNode.leftChild, newNode.rightChild = self.create( _left, mid), self.create(mid+1, _right)
        newNode.index = newNode.leftChild.index \
            if self.rectangles[ newNode.leftChild.index] < self.rectangles[ newNode.rightChild.index] \
            else newNode.rightChild.index

        return newNode

    def get_min_height_index(self, _currentNode, _left, _right):
        if _currentNode.left == _left and _currentNode.right == _right:
            return _currentNode.index

        mid = int((_currentNode.left + _currentNode.right) / 2)
        if _left <= mid < _right:
            leftMinHeightIndex, rightMinHeightIndex = self.get_min_height_index(_currentNode.leftChild, _left, mid), \
                                                      self.get_min_height_index(_currentNode.rightChild, mid + 1, _right)
            return leftMinHeightIndex if self.rectangles[leftMinHeightIndex] < self.rectangles[rightMinHeightIndex] \
                else rightMinHeightIndex
        elif _right <= mid:
            return self.get_min_height_index(_currentNode.leftChild, _left, _right)
        else:
            return self.get_min_height_index(_currentNode.rightChild, _left, _right)

def data_in():
    return list( map( int, input().split()))

def divide_N_conquer( _segmentTree, _left, _right, _rectangles):
    if _right < _left: return 0
    if _left == _right: return _rectangles[ _left]

    minHeightIndex = _segmentTree.get_min_height_index( _segmentTree.head, _left, _right)
    flatArea = _rectangles[ minHeightIndex] * ( _right - _left + 1)
    leftMaxArea, rightMaxArea = divide_N_conquer( _segmentTree, _left, minHeightIndex - 1, _rectangles), \
                                divide_N_conquer( _segmentTree, minHeightIndex + 1, _right, _rectangles)

    return max( flatArea, leftMaxArea, rightMaxArea)

def solution( _rectangles):
    segmentTree = SegmentTree( _rectangles)
    return divide_N_conquer( segmentTree, 0, len( _rectangles)-1, _rectangles)

if __name__ == '__main__':
    while True:
        rectangles = data_in()
        if len(rectangles) == 1:
            if rectangles[0] == 0: break
            else : print( rectangles[0])
        else:
            del rectangles[0]
            print( solution( rectangles))