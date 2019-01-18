# [2912 백설공주와 난쟁이](https://www.acmicpc.net/problem/2912)

## 있는 그대로 풀기

```cpp
int is_pretty(int begin, int end) {

	for (int i = begin; i <= end; i++) {
		int idx = little_boy[i];
		cap[idx]++;

		if (cap[idx] > (end - begin + 1) / 2)
			return idx;
	}

	return 0;
}
```
위에 있는 코드 처럼,  
구간마다 for를 돌려가며 난장이가 쓰고 있는 모자를 확인 하는 방법이다.  
그리고 모자의 개수가 구간의 절반을 넘으면 답을 return 하고, 절반을 넘는 모자가 없다면 0을 반환한다.  

## 이분탐색을 이용하여 풀기
####[풀이를 참고한 네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221332226003&proxyReferer=https%3A%2F%2Fwww.google.com%2F)
이 풀이는 위 블로그에서 참고했다.  
  
되게 참신한 풀이다. 한번 씩 읽어보고 이해 해 보시길.