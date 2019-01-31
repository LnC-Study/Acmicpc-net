import sys

seq = sys.stdin.read()
seq = seq.split("\n")
seq.pop()
seq = map(int, seq)

array = [0, 0, 1]

for i in range(3, 1001):
    result = pow(2, i-3) + array[i-2]
    array.append(result)

for j in seq:
    print(array[j])
