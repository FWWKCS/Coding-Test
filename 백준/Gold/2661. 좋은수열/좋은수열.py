import sys
input = sys.stdin.readline

N = int(input())

foundValue = False

def makeGoodSequence(num) :
    global foundValue

    if not foundValue : pass
    else : return

    for k in range(1, (len(num) // 2)+1) :
        if num[-k : ] == num[-(2*k) : -k] : 
            return
    
    if len(num) == N : 
        print(num)
        foundValue = True
        

    for i in range(1,3+1) :
        makeGoodSequence(num+str(i)) 


makeGoodSequence('')