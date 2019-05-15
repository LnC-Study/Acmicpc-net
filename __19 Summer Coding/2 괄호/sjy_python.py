# cheated injun's...TT

import itertools


N = int(input())
total = ['(' for _ in range(N)]
total.extend([')' for _ in range(N)])

answer = []
combination = []

for e in set(itertools.permutations(total)):
    combination.append(''.join(e))


def sol(strings):
    for string in strings:
        count = 0
        for character in string:
            if character == '(':
                count += 1
            else:
                count -= 1

            if count < 0:
                break

        if count >= 0:
            answer.append(string)


sol(combination)
print(len(answer), end=' ')
print(sorted(answer))

