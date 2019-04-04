x,y = input().split()
x= int(x)
y = int(y)
#print(x,y)

chess = []
for i in range (x):
    chess_temp = list(map(int,input().split()))
    chess.append(chess_temp)
#print(chess)

maxval = -1

####1-1.
for x_val in range(x):
    for y_val in range(y-3):
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val][y_val+2]+chess[x_val][y_val+3]
      #  print(sum)
        if sum > maxval:
            maxval = sum
#1-2.
#
#
#
for x_val in range(x-3):
    for y_val in range(y):
        sum = chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+2][y_val]+chess[x_val+3][y_val]
       # print(sum)
        if sum > maxval:
            maxval = sum

##2-1.
##
for x_val in range(x-1):
    for y_val in range(y-1):
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]
       # print(sum)
        if sum > maxval:
            maxval = sum
#3-1,2,3,4.  #  ## ##
#            #  #   #
##          ##  #   #

for x_val in range(x-2):
    for y_val in range(y-1):
        sum = chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+2][y_val]+chess[x_val+2][y_val+1]
        #print(sum)
        if sum > maxval:
            maxval = sum
        sum=chess[x_val][y_val+1]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val+1]+chess[x_val+2][y_val]
        if sum > maxval:
            maxval = sum
            
        sum=chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+2][y_val]+chess[x_val][y_val+1]
        if sum > maxval:
            maxval = sum
            
        sum=chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val+1]
        if sum > maxval:
            maxval = sum

###3-5.
#

###3-6.
  #

#3-7.
###

  #3-8.
###
for x_val in range(x-1):
    for y_val in range(y-2):
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val][y_val+2]+chess[x_val+1][y_val]
       # print(sum)
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val][y_val+2]+chess[x_val+1][y_val+2]
        if sum > maxval:
            maxval = sum

        sum = chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+1][y_val+2]
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val+2]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+1][y_val+2]
        if sum > maxval:
            maxval = sum

#    #
##  ##
 #  #. 4-1,2

for x_val in range(x-2):
    for y_val in range(y-1):
        sum = chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val+1]
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val+1]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val]
        if sum > maxval:
            maxval = sum


 ##  ##
##    ##. 4-3,4.


for x_val in range(x-1):
    for y_val in range(y-2):
        sum = chess[x_val][y_val+1]+chess[x_val][y_val+2]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val+1][y_val+1]+chess[x_val+1][y_val+2]
        if sum > maxval:
            maxval = sum

###  #
 #  ###. 5-1,2.

for x_val in range(x-1):
    for y_val in range(y-2):
        sum = chess[x_val][y_val]+chess[x_val][y_val+1]+chess[x_val][y_val+2]+chess[x_val+1][y_val+1]
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val+1]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+1][y_val+2]
        if sum > maxval:
            maxval = sum

 # #
## ##
 # #   5-3,4.

for x_val in range(x-2):
    for y_val in range(y-1):
        sum = chess[x_val][y_val+1]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val+1]
        if sum > maxval:
            maxval = sum
            
        sum = chess[x_val][y_val]+chess[x_val+1][y_val]+chess[x_val+1][y_val+1]+chess[x_val+2][y_val]
        if sum > maxval:
            maxval = sum

 
print(maxval)

