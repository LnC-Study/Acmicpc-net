import random, time
import concurrent.futures

def data_in():
    N, C = map(int, input().split())
    # littleBoy = list(map(int, input().split()))
    littleBoys = [ random. randrange(1, C+1) for _ in range(N)]
    return N, C, littleBoys

def check_time( _originFunction):
    def wrapper( *args, **kwargs):
        startTime = time.time()
        _originFunction( *args, **kwargs)
        endTime = time.time()
        print( f'Time: {endTime - startTime} sec')
    return wrapper

def counter( _assignedLittleBoys):
    result = {}
    for boy in _assignedLittleBoys:
        if boy in result: result[boy] += 1
        else : result[boy] = 1
    return result

@check_time
def divide_N_conquer( _N, _C, _littleBoys):
    processSize = 8
    batchSize = int(  _N / processSize)

    dividedLittleBoys = [ _littleBoys[ (idx-1)*batchSize: (idx)*batchSize] \
                          for idx in range(1, processSize)]
    dividedLittleBoys.append( littleBoys[ (processSize-1)*batchSize: ])

    totalResult = {}
    with concurrent.futures.ProcessPoolExecutor( max_workers = processSize) as executor:
        executorResult = executor.map( counter, dividedLittleBoys)

    for partialResult in executorResult:
        for value in partialResult.keys():
            if value in totalResult:
                totalResult[value] += partialResult[value]
            else:
                totalResult[value] = partialResult[value]

    print('Result:', totalResult)

@check_time
def linear( _N, _littleBoys):
    result = {}
    for boy in _littleBoys:
        if boy in result: result[boy] +=1
        else : result[boy] = 1

    print('Result:', result)

def solution( _N, _C, _littleBoys):
    divide_N_conquer( _N, _C, _littleBoys)
    linear(N, _littleBoys)

if __name__ == '__main__':
    N, C, littleBoys = data_in()
    # print('Origin:', littleBoys)
    solution( N, C, littleBoys)