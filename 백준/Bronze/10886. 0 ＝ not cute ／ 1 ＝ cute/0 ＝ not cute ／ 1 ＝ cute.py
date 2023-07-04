testCase = int(input())

cute = 0
notCute = 0

for _ in range(testCase) :
    vote = int(input())
    if vote == 1 : cute += 1
    else : notCute += 1

if cute > notCute : print('Junhee is cute!')
else : print('Junhee is not cute!')