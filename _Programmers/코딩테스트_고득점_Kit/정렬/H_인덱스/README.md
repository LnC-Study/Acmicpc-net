# H-Index (Level 2)

Property: https://programmers.co.kr/learn/courses/30/lessons/42747
Status: 정렬

---

## 문제 설명

H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과[1](https://programmers.co.kr/learn/courses/30/lessons/42747#fn1)에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 `n`편 중, `h`번 이상 인용된 논문이 `h`편 이상이고 나머지 논문이 h번 이하 인용되었다면 `h`가 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

---

### 제한사항

- 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
- 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

---

### 입출력 예

![H%20Index%20Level%202/Untitled.png](H%20Index%20Level%202/Untitled.png)

---

### 입출력 예 설명

이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다.

그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

---

## 문제 해결

by 인준

### 전체 소스 코드 및 설명

    import java.util.Arrays;
    
    class Solution {
        public int solution(int[] citations) {
            int answer = 0, target;
            Arrays.sort(citations);
            for (int idx = 0; idx < citations.length; idx++) {
            	target = Math.min(citations[idx], citations.length - idx);
            	answer = Math.max(answer, target);
            }
            
            return answer;
        }
    }

target의 값이 될 수 있는 것은 다음과 같이 2가지가 존재하며, target은 이 중 더 작은 값을 가지게 된다.

1. citations[idx]                     // 현재 논문에 대한 인용 횟수
2. citations.length - idx        // 현재 논문보다 더 많거나 같은 인용 횟수를 가지는 논문의 수 (아래에서는 이를 '남은 논문의 수'라고 부르겠음)

**현재 citations 배열은 오름차순으로 정렬**되어 있기 때문에 아래와 같은 논리가 가능하다.

1번의 경우, **현재 논문에 대해 인용된 횟수 citations[idx]가** 남은 논문의 수 citations.length - idx보다 **적은 경우**이다. **citations[idx] 값은 남은 논문의 개수 보다도 작은 값**을 가지기 때문에, **citations[idx] 개수 만큼의 논문이 남을 수 있다**. 따라서, **citations[idx]은 h가 될 가능성**이 있다.

2번의 경우, 현재 논문에 대해 인용된 횟수 citations[idx] 보다 **남은 논문의 수 citations.length - idx가 적은 경우**이다. 이와 같은 경우, **남은 논문들의 인용된 횟수는 모두 citations[idx] 보다 큰 값**을 가진다. **현재 논문을 포함한 남은 모든 논문들의 인용 횟수는 citations.length - idx보다 크거나 같은 값**을 가질 수 있기 때문에, **가능한 h 값은 citations.length - idx**이다.

따라서, citations[idx]와 citations.length - idx 중에서 더 작은 값을 target의 값으로 정의할 수 있다.

이와 같이 가능한 target들 중에서 가장 큰 값을 찾아 answer 값으로 대입하면 문제를 해결할 수 있다.