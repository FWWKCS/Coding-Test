import sys
input = sys.stdin.readline

def check_VPS (x) :
    stack = []
    for l in x :
        if l != ')' : stack.append(l)
        else :
            if ( len(stack) > 0 and stack[-1] == '' ) or stack == [] : return False
            else : stack.pop()
    
    if len(stack) > 0 : return False
    else : return True

testCase = int(input())

isVPS = False

for _ in range(testCase) :
    stack = []
    testString = input().rstrip()
    isVPS = check_VPS(testString)

    if isVPS : print('YES')
    else : print('NO')