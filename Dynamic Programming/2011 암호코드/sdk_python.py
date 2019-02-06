MOD = 1000000

def data_in():
    return input()

def isAlpha( prev, ch2):
    return 10 <= int( prev['ch'] + ch2) <= 26 \
        if prev['ch'] != None else False

def solution( code):
    prev = [{'ch': None, 'count': 1} for _ in range(2)]
    for ch in code:
        try: int(ch)
        except: return 0

        if ch == '0':
            if prev[-1]['ch'] not in ['1','2']: return 0
            else:
                count = prev[-2]['count']
        else:
            count = prev[-1]['count']
            if isAlpha( prev[-1], ch):
                count += prev[-2]['count']
        prev[-2], prev[-1] = prev[-1], {'ch': ch, 'count': count % MOD}

    return prev[-1]['count']

if __name__ == '__main__':
    code = data_in()
    ans = solution( code)
    print( ans)