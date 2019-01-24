from heapq import heapify

class HorizonLine:
    def __init__(self, _beginX, _endX, _y, _index):
        self.beginX, self.endX, self.y = _beginX, _endX, _y
        self.width = self.endX - self.beginX
        self.index = _index

    def __gt__(self, other):
        return self.y > other.y

class Node:
    def __init__(self, _index, _leaks):
        self.index, self.leaks = _index, _leaks
        self.leftChild, self.rightChild = None, None

horizonLines = []

def push( _currentNode, _targetNode):
    currentNodeX = horizonLines[ _currentNode.index].beginX
    targetNodeX = horizonLines[ _targetNode.index].beginX

    _currentNode.leaks += 1

    if targetNodeX > currentNodeX:
        if _currentNode.rightChild is None:
            _currentNode.rightChild = Node( _targetNode.index, 1)
        else:
            push( _currentNode.rightChild, _targetNode)
    else:
        if _currentNode.leftChild is None:
            _currentNode.leftChild = Node( _targetNode.index, 1)
        else:
            push( _currentNode.leftChild, _targetNode)

def data_in():
    numOfDots = int(input())
    prevX, prevY = map( int, input().split())

    lineHash = {}

    horizonLineCount = 0
    for idx in range( numOfDots-1):
        currentX, currentY = map( int, input().split())
        if prevY == currentY:
            newHorizonLine = HorizonLine(prevX, currentX, currentY, horizonLineCount)
            lineHash[ prevX] = newHorizonLine
            horizonLines.append( newHorizonLine)
            horizonLineCount += 1

        prevX, prevY = currentX, currentY

    numOfLeaks, leaks = int(input()), []
    for idx in range( numOfLeaks):
        beginX, _, __, ___ = map(int, input().split())
        leaks.append( lineHash[ beginX])

    del lineHash
    heapify( leaks)
    head = Node( leaks[0].index, 1)

    for leak in leaks[1:]:
        push( head, leak)

    return head

def calc( _left, _right, _top):
    rest = 0
    for idx in range( _left, _right + 1):
        if horizonLines[ idx].y > _top:
            rest += (horizonLines[ idx].y - _top) * horizonLines[ idx].width

    return rest

def divide_N_conquer( _currentNode, _left, _right):
    top = horizonLines[ _currentNode.index].y

    left = calc( _left, _currentNode.index - 1, top) if _currentNode.leftChild is None else \
        divide_N_conquer( _currentNode.leftChild, _left, _currentNode.index - 1)
    right = calc( _currentNode.index + 1, _right, top) if _currentNode.rightChild is None else \
        divide_N_conquer( _currentNode.rightChild, _currentNode.index + 1, _right)

    return left + right

def solution( _head):
    return divide_N_conquer( _head, 0, len( horizonLines) - 1)

if __name__ == '__main__':
    head = data_in()
    ans = solution( head)
    print( ans)