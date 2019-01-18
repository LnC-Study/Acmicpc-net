# [6549 히스토그램에서 가장 큰 직사각형](https://www.acmicpc.net/problem/6549)

본 문제는 분할정복의 정석적인 문제라 할 수 있다.

## 중간 값을 이용하여 풀기
하나의 히스토그램이 있을 때, 그 히스토그램에서 가장 큰 사각형의 넓이는 다음 3가지 중 하나일 것이다.  
  
히스토그램의 인덱스를 절반으로 나누었을 때 (mid = start + end / 2)

	1.  start번 부터 mid 까지의 히스토그램에서의 가장 큰 사각형(왼쪽)
	2.  mid + 1에서 부터 end 까지의 히스토그램에서의 가장 큰 사각형(오른쪽)
	3.  mid가 포함 된 히스토그램에서의 가장 큰 사각형(중간)

### 1,2 왼쪽과 오른쪽 에서의 히스토그램의 가장 큰 사각형
문제를 구현할 때 재귀함수로 구현하게 된다면, 이부분은 쉽게 구현할 수 있게 된다.
```cpp
	ret = max(ret, max_rectangle(start, mid));
	ret = max(ret, max_rectangle(mid + 1, end));
```
왼쪽과 오른쪽에서의 return값과 현재 return 값 중 큰것을 return 값으로 취하면 된다.

### 3. mid가 포함된 히스토그램에서의 가장 큰 사각형
mid가 포함되었다는 뜻은 mid와 mid+1의 index가 무조건 사각형 안에 존재한다는 뜻이다.
그렇지 않다면 왼쪽 혹은 오른쪽 히스토그램에 포함될 것이기 때문이다.  
  
그래서 초기의 사각형의 index는 mid, mid+1이고, height는 그 index가 있는 히스토그램 중에서 낮은 값을 취한다.
```cpp
	left = mid;
	right = mid + 1;
	height = min(histogram[left], histogram[right]);
	ret = max(height * (right - left + 1));
```
그리고 히스토그램의 값이 높은 쪽으로 사각형을 확장하면서 높이를 계속 계산한다.  
한쪽 끝에 닿았다면, 다른쪽 끝에 닿을 때 까지 계산한다.  
```cpp
for (; !(left == start && right == end) ;) {
		
		if (left > start && right < end) {
			histogram[left - 1] > histogram[right + 1] ? left-- : right++;
			height = min(height, histogram[left]);
			height = min(height, histogram[right]);
		}
		else if (left > start) {
			left--;
			height = min(height, histogram[left]);
		}
		else {
			right++;
			height = min(height, histogram[right]);
		}

		area = height * (right - left + 1);
		ret = max(ret, area);

	}
```

이렇게 3가지의 경우를 다 계산하고 난 후에 결과값을 리턴하면 원하는 값을 얻게 된다.


---
## 최소값을 이용하여 풀기
위의 풀이와 비슷하지만, 위의 풀이에서 3번을 계산하는 시간을 줄여준다.  
  
하나의 히스토그램이 있을 때, 그 히스토그램에서 가장 큰 사각형의 넓이는 다음 3가지 중 하나일 것이다.  
  
하나의 히스토그램이 있을 때 그 히스토그램에서의 최소값을 갖는 인덱스를 pivot이라 하면
	1. start번에서 pivot까지의 히스토그램에서의 가장 큰 사각형(왼쪽)
	2. pivot + 1번에서 end까지의 히스토그램에서의 가장 큰 사각형(오른쪽)
	3. (end - start + 1) * pivot (pivot을 포함하는 사각형)

### 1,2 왼쪽과 오른쪽 에서의 히스토그램의 가장 큰 사각형
위의 풀이와 같다.
### 3. pivot을 포함하는 사각형
이 부분을 풀기위해서는 pivot을 먼저 찾아야 한다.  
가장 낮은 값을 갖는 히스토그램의 index를 찾기 위해서는 다양한 방법이 있겠지만, 간단히 두개를 찾아보자면  

- for를 이용해서 찾는 방법
- segment tree를 이용하는 방법  

2가지의 경우를 생각 해 볼 수 있다.  
#### for를 이용해서 찾는 방법
for를 이용하게 된다면 각각의 경우, 즉, 왼쪽, 오른쪽의 부분 문제들을 다 포함해야 하니 각 레벨 마다는 n번의 계산을 하게 되고,  
각 레벨은 총 log(n) 번 존재하기 때문에 nlog(n)의 시간이 걸리게 된다.
#### segment tree를 이용하는 방법  
한번 트리를 구성하고 나면 segment tree의 구간 합을 찾는데 걸리는 시간이 log(n)인 것은 자명하다.  
이 풀이에서는 tree를 구성할 때,  
부모의 노드는 자식의 노드의 값이 가리키는 히스토그램의 값을 비교하여 히스토그램의 값이 낮은 자식노드의 값을 갖게된다.
