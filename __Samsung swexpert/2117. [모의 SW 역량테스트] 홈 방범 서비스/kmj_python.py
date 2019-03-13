from math import ceil

def data_in():
	N, M = map(int, input().split())
	board = list(list(i for i in input().split()) for i in range(N))
	return N, M, board
	
	
def howManyHouse(board, x, y, k):
	total = 0
	N = len(board[0])
	for i in range(x-(k-1), x):
		offset = i-(x-k+1)
		for j in range(y-offset, y+offset+1):
			if i < 0 or i >= N or j < 0 or j >= N: continue
			if board[i][j] == '1':
				total = total+1
	for j in range(y-k+1, y+k):
		if j < 0 or j >= N: continue
		if board[x][j] == '1':
			total = total+1
	for i in range(x+1, x+k):
		offset = x+k-i-1
		for j in range(y-offset, y+offset+1):
			if i < 0 or i >= N or j < 0 or j >= N: continue
			if board[i][j] == '1':
				total = total+1	
	return total


def solution(board, N, M):
	maxhouse = 0
	print('ceil',ceil(N/2)+1)
	for k in range(1, ceil(N/2)+1):
		for x in range(N):
			for y in range(N):
				num = howManyHouse(board, x, y, k)
				k = int(k)
				interest = (int(M)*num)-(k*k+(k-1)*(k-1))
				if interest >= 0 and maxhouse < num:
					maxhouse = num
	return maxhouse

	
if __name__ == '__main__':
	T = int(input())
	for cnt in range(T):
		N, M, board = data_in()
		result = solution(board, N, M)
		print("#%d %d" %(cnt+1, result))
