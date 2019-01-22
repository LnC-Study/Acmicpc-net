## Problem 3777: Computer Transformation
## using Recurrence relation
import sys

keyboard = sys.stdin.read()
keyArr = keyboard.split("\n")
keyArr.pop() # remove EOF
keyArr = map(int, keyArr)
valArr = list()

array = [0, 0]

for i in range(2, 1001):
    value = pow(2, i-2) - array[i-1]
    array.append(value)

for key in keyArr:
    print(array[key])