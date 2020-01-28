# N으로 표현 (Level 3)

Property: https://programmers.co.kr/learn/courses/30/lessons/42895
Status: 동적계획법(Dynamic Programming)

---

## 문제 설명

아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)12 = 55 / 5 + 5 / 512 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

---

### 제한사항

- N은 1 이상 9 이하입니다.
- number는 1 이상 32,000 이하입니다.
- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
- 최솟값이 8보다 크면 -1을 return 합니다.

---

## 문제 해결

by 인준

동적 프로그래밍(dynamic programming)은 분할정복 기법과 같이 부분 문제의 해를 결합해 문제를 해결한다. 분할정복 알고리즘은 문제를 서로 겹치지 않는(disjoint) 부분 문제로 분할하고, 해당 부분 문제를 재귀적으로 해결한 후, 해결 결과를 결합하여 원래의 문제를 해결한다. 반면, **동적 프로그래밍은 부분 문제가 서로 중복될 때, 즉 부분 문제가 다시 자신의 부분 문제를 공유할 때 적용할 수 있다**. 동적 프로그래밍 알고리즘을 이용하면 모든 부분 문제를 한 번만 풀어 그 해를 테이블에 저장함으로써 각 부분 문제를 풀 때마다 다시 계산하는 일을 피할 수 있다.

일반적으로 ***최적화 문제*(optimization problem)**에 동적 프로그래밍을 적용한다. 이런 문제는 다양한 해를 가질 수 있다. 각 해는 값을 가져 이 중 최적(최소 또는 최대)의 값인 해를 찾기를 원한다. 이런 해를 그 문제에 대한 *유일한* 최적해라 하지 않고, *한 개*의 최적해라 한다. 최적의 값을 가지는 해가 여러 개 존재할 수 있기 때문이다. 동적 프로그래밍 알고리즘을 개발할 때는 다음 4단계를 따른다.

1. 최적해의 구조의 특징을 찾는다.
    - Optimal substructure: An optimal solution to a problem (instance) contains optimal solutions to sub-problems.
    - **Recursive algorithm을 설계**한다.

2. 최적해의 값을 재귀적으로 정의한다.
    - Overlapping sub-problems: A recursive solution contains a "small" number of distinct sub-problems repeated many times.
    - **Memoization algorithm을 설계**한다.
        - Memoizatoin: After computing a solution to a sub-problems, store it in a table. Subsequent calls check the table **to avoid redoing work**.

3. 최적해의 값을 일반적으로 상향식(bottom-up) 방법으로 계산한다.

4. 계산된 정보들로부터 최적해를 구성한다.

위의 내용은 [**Introduction To Algorithms**](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)에 포함된 내용이며, 이를 바탕으로 아래와 같이 알고리즘을 설계하였다.

1. ***Recursive algorithm***
    - **사칙연산은 두 개의 피연산자를 필요**로 한다.
    - *N*을 K번 사용해서 표현할 수 있는 숫자들을 *values*[K]라 하자.
    - *N*이 5일 때, *values*[1]는 {5}가 된다.
    - *N*이 5일 때, *values*[2]는 {55, 0, 1, 10, 25}가 된다.
    - *values*[2]를 살펴보면, *values*[2] = { **CONCAT**[2] } U { *values*[1] ◎ *values*[1] }로써 표현할 수 있다

        , where ◎ is the set of operations {＋, －, ×, ÷}, and **CONCAT**[K] is the *value concatenated* with *N* by K times.

    - 따라서 ***values*[K]를 다음과 같이 일반화** 시킬 수 있다.

        *values*[K] = { **CONCAT**[K] } U 

                           { *values*[1] ◎ *values*[K - 1] } U 

                           { *values*[2] ◎ *values*[K - 2] } U

                           ···   U 

                           { *values*[K - 2] ◎ *values*[2] } U 

                           { *values*[K - 1] ◎ *values*[1] }

2. ***Memozation***
    - 따라서, *values*[*K*]를 구하기 위해서는 *values*[1]부터 *values*[*K* - 1]까지의 값들이 필요하다.
    - 이는 *values*[1]부터 (bottom-up) 모든 부분 문제를 한 번만 풀어 그 해를 **테이블에 저장함(memoization)**으로써, *values*[*K*]는 필요한 값들을 테이블로 부터 참조하여 **각 부분 문제를 다시 계산하는 일을 피하도록 한다**.
    - 또한, 위에서 구한 일반화를 잘 살펴보면 중복되는 점을 발견할 수 있다.

        { *values*[1] ◎ *values*[*K* - 1] }와 { *values*[*K* - 1] ◎ *values*[1] }에 대하여 +과 ×의 결과값이 중복되어 계산된다.

    - 그러므로 *K*개의 *N*으로 나타낼 수 있는 값들을 **집합**으로 표현함으로써 **중복을 제거하고 redoing work를 피한다**.

이와 같은 설계를 바탕으로 아래와 같은 pseudo-code를 작성할 수 있다.

    findOptimizedSol(N, number, amount, memoization): int
    
    1. result ← -1
    2. values ← the empty set      // amount개의 N으로 표현 가능한 수들의 집합인 values
    3. values ← values U { value concatenated with N by amount times }
    4. for i = 1 to amount:
    5.         for each left in memoization(i):      // left is left operand
    6.                 for each right in memoization(amount - i):      // right is right operand
    7.                         values ← values U {left + right}
    8.                         values ← values U {left - right}
    9.                         values ← values U {left × right}
    10.                        if right is not zero:
    11.                                 values ← values U {left ÷ right}
    12. if values contains number:      // number를 표현할 수 있는 경우, 현재 개수인 amount를 return
    13.         return amount
    14. memoization.push(amount, values)      // 현재 amount로 표현 가능한 수들을 재사용하기 위해 memoization에 저장
    15. if amount is less than 9:
    16.         amount ← amount + 1
    17.         result = findOptimizedSol(N, number, amount, memoization)
    18. return result