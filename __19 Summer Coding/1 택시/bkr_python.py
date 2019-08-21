group = input()
group = group[1:-1]
group = list(map(int, group.split(',')))
groupnum=[]
for i in range(1,5):
	groupnum.append(group.count(i))
#print(groupnum)
#print(group)

sum=0
#cnt 4
sum += groupnum[3]
#cnt 3+1
cnt31 = min(groupnum[0], groupnum[2])
if(cnt31==groupnum[0]):
	groupnum[0] = 0
	groupnum[2] -= cnt31
else:
	groupnum[0] -= cnt31
	groupnum[2] = 0
sum += cnt31

#cnt 2+2
cnt22 = groupnum[1]//2
sum += cnt22
groupnum[1] -= cnt22 * 2

#cnt 3
sum += groupnum[2]

#cnt 2+1+1
while(groupnum[1]>0 and groupnum[0] > 0):
	if(groupnum[0]>1):
		sum+=1
		groupnum[0] -= 2
		groupnum[1] -= 1
	else:
		sum += 1
		groupnum[0] -=1
		groupnum[1] -=1
	
#cnt 2
sum += groupnum[1]//2
sum += groupnum[1]%2

#cnt 1
sum += groupnum[0] //4
sum += groupnum[0] % 4

print(sum)

