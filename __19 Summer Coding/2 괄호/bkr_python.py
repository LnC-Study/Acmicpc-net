#문자열 배열은 오름차순
def make(direction, letter):
	ans=''
	letter += direction
	r_cnt = letter.count(')')
	l_cnt = letter.count('(')

	if(r_cnt==n and l_cnt==n):
		return letter+", "
	if(r_cnt == l_cnt):
		ans += make("(", letter)
	elif(l_cnt == n):
		letter += ')' * (n-r_cnt)
		return "\""+letter+"\","
	else:
		ans += make("(",letter)
		ans += make(")", letter)	
	return ans

n = int(input())

ans = make("(", "")
ans = "["+ans[:-1]+"]"
print(ans)
