# [3777 Computer Transformation](https://www.acmicpc.net/problem/3777)
## 첫번째 풀이법: 점화식(Recurrence relation) 이용한 DP
원래는 분할정복으로 풀어야 하지만..의도치 않게 dp로 먼저 풀게 되었슴다..!

직접 몇번 변형을 해보며 규칙성을 찾아보겠습니다.

| 변형횟수 | 변형 후 값 | '00' 등장 횟수 |
|:--------:|:--------:|:--------:|
| 1 | 0 1 | 0 |
| 2 | 1 0 0 1 | 1 |
| 3 | 0 1 1 0 1 0 0 1 | 1 |
| 4 | 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 | 3 |
| 5 | 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 | 5 |
| : | : | : |

규칙이 보이시나요..??
잘 안 보이신다면 변형횟수와 '00' 등장 횟수만 다시 정리해서 봅시다...!

| 변형횟수 | 1 | 2 | 3 | 4 | 5 | ... |
|:--------:|:--------:|:--------:|:--------:|:--------:|:--------:|:--------:|
| '00' 등장 횟수 | 0 | 1 | 1 | 3 | 5 | ... |

f(n) = n회 변형 후 '00' 등장 횟수 으로 정의했을 때, 아래와 같은 점화식이 성립합니다.
```
f(n+1) = 2^(n-1) - f(n) (n >= 1)
```

## 두번째 풀이법: 분할정복....광원풀이 넣을 예정...(사실은 dp입니다!)

| 변형횟수 | 변형 후 값 | 
|:--------:|:--------:|
| 1 | 0 1 | 
| 2 | 1 0 0 1 | 
| 3 | 0 1 1 0 1 0 0 1 | 
| 4 | 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 | 
| 5 | 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 | 
| : | : | 

위에 있는 표를 보면 상위 단을 not 한 값을 처음에 붙이고, 상위 단을 그대로 이어붙이는 것을 확인할 수 있습니다.

| 변형횟수 | 윗 값을 not한 값  | 윗값을 그대로 옮긴 값| 
|:--------:|:--------:| :--------:| 
| 1 | 0 | 1 | 
| 2 | 1 0 | 0 1 | 
| 3 | 0 1 1 0 | 1 0 0 1 | 
| 4 | 1 0 0 1 0 1 1 0 | 0 1 1 0 1 0 0 1 | 
| 5 | 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 | 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 | 
| : | : | : | 
   
그리고. 짝수일 경우에는 가운데에서 00이 하나가 생긴다는 것을 알 수 있습니다.

정리해 보면
이전에서의 11이 나온 수 + 이전에서의 00이 나온 수 + 짝수일 경우에는 + 1 = 현재의 00이 나온 수 가 됩니다.

그리고 이를 조금 더 빠르게 계산하기 위해서는 메모이제이션을 이용하여서 이전에 사용했던 값들을 저장하여 사용하면 됩니다!
하지만, 여기서 나오는 값들은 되게되게 큰 값이기 때문에, int나 long long으로는 다 담을 수 없습니다.
그래서 string에 값을 저장하여서 사용하였습니다.

