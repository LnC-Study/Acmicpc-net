pattern = list(map(int, input().split(' ')))

coordination = {1: (1, 3), 2: (2, 3), 3: (3, 3),
                4: (1, 2), 5: (2, 2), 6: (3, 2),
                7: (1, 1), 8: (2, 1), 9: (3, 1)}

lines = []
answer = []


class point:
    def __init__(self, coor):
        self.xPos = coor[0]
        self.yPos = coor[1]

    def gt(self, other):
        if self.xPos > other.xPos:
            return True

        elif self.xPos == other.xPos:
            if self.yPos > other.yPos:
                return True
            else:
                return False

        else:
            return False

class line:
    def __init__(self, p1, p2):
        self.point1 = p1
        self.point2 = p2


def ccw(point1, point2, point3):
    op = point1.xPos * point1.yPos + point2.xPos * point2.yPos + point3.xPos * point3.yPos
    op -= (point1.yPos * point2.xPos + point2.yPos * point3.xPos + point3.yPos * point1.xPos)

    if op > 0:
        return 1
    elif op == 0:
        return 0
    else:
        return -1


def hasIntersection(line1, line2):
    ab = ccw(line1.point1, line1.point2, line2.point1) * ccw(line1.point1, line1.point2, line2.point2)
    cd = ccw(line2.point1, line2.point2, line1.point1) * ccw(line2.point1, line2.point2, line1.point2)

    if ab == 0 and cd == 0:
        if line1.point1.gt(line1.point2):
            line1.point1, line1.point2 = line1.point2, line1.point1

        if line2.point1.gt(line2.point2):
            line2.point1, line2.point2 = line2.point2, line2.point1

        return not line1.point1.gt(line2.point2) and not line2.point1.gt(line1.point2)

    return ab <= 0 and cd <= 0


for idx in range(0, len(pattern)-1):
    lines.append(line(point(coordination[pattern[idx]]), point(coordination[pattern[idx+1]])))


for line1 in lines:
    count = 0
    for line2 in lines:
        if line1 == line2:
            continue

        if hasIntersection(line1, line2) is True:
           count += 1

    answer.append(count)

print(answer)

