from bisect import bisect_left, bisect_right

def data_in():
    N = int( input())
    return N, [ list( map( int, input().split()[:-1])) for _ in range( N)]

def get_trace_list( _current, _dp):
    groupSize = []
    while _current >= 1:
        groupSize.append( _current - _dp[_current]['prev'] + 1)
        _current = _dp[_current]['prev'] - 1 if _current != _dp[_current]['prev']\
                else _current - 1

    groupSize.reverse()
    return groupSize

def solution( _N, _doKnow):
    cuts, dp = [], [{'cut':0, 'pass':0, 'prev':0, 'min':0 } for _ in range( _N + 1)]
    for idx in range( 1, _N + 1):
        dp[idx]['cut'] = dp[idx-1]['min'] + bisect_left( _doKnow[idx-1], idx)

        stranger = (idx - dp[idx - 1]['prev']) - \
                   (bisect_right( _doKnow[idx - 1], idx) - bisect_left( _doKnow[idx - 1], dp[idx - 1]['prev']))
        dp[idx]['pass'] = dp[idx-1]['min'] \
                          + bisect_left( _doKnow[idx-1], dp[idx - 1]['prev']) \
                          + stranger

        if dp[idx]['pass'] <= dp[idx]['cut']:
            dp[idx]['min'], dp[idx]['prev'] = dp[idx]['pass'], dp[idx - 1]['prev']
        else:
            dp[idx]['min'], dp[idx]['prev'] = dp[idx]['cut'], idx

    return dp[_N]['min'], get_trace_list( _N, dp)

if __name__ == '__main__':
    N, doKnow = data_in()
    ans, list = solution( N, doKnow)

    print( ans)
    print( len(list), end= ' ')
    for size in list: print( size, end= ' ')