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
#### [풀이를 참고한 네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221332226003&proxyReferer=https%3A%2F%2Fwww.google.com%2F)
이 풀이는 위 블로그에서 참고했다.  
  
되게 참신한 풀이다. 한번 씩 읽어보고 이해 해 보시길.

## +a 멀티 프로세싱을 이용한 풀기
#### [파이썬에서 멀티프로세싱](https://github.com/LnC-Study/Acmicpc-net/blob/master/Divide%26Conquer/2912%20%EB%B0%B1%EC%84%A4%EC%A2%85%EC%98%81%EA%B3%BC%20%EB%82%9C%EC%9F%81%EC%9D%B4/sdk_python.py)

#### [Python document](https://docs.python.org/ko/3/library/concurrent.futures.html)

```
def counter( _assignedLittleBoys):
    result = {}
    for boy in _assignedLittleBoys:
        if boy in result: result[boy] += 1
        else : result[boy] = 1
    return result

processSize = 8
    batchSize = int(  _N / processSize)

    dividedLittleBoys = [ _littleBoys[ (idx-1)*batchSize: (idx)*batchSize] \
                          for idx in range(1, processSize)]
    dividedLittleBoys.append( littleBoys[ (processSize-1)*batchSize: ])

    totalResult = {}
    with concurrent.futures.ProcessPoolExecutor( max_workers = processSize) as executor:
        executorResult = executor.map( counter, dividedLittleBoys)

```
 위와 같이 프로세스 수를 정해두고, 프로세스 수에 맞게 난장이 모자에 대한 배열을 분할한다. 이후 각 프로세스에게 배열을 할당시켜 구간 내의 모자 개수를 세아려 값을 리턴한다.
 
  이를 통해 테스트해보면 8개 프로세스의 경우 구간의 크기가 약 5,000,000 인 경우까지는 Linear한 방법이 더 빠르다. 하지만 이후 10,000,000 경우부터는 확실히 멀티 프로세싱이 더 빠름을 알 수 있다. (50,000,000의 경우에는 멀티 프로세싱이 2배이상 빠름을 알 수 있다.)
