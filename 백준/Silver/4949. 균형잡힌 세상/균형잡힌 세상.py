import sys
input = sys.stdin.readline

def check_VPS (x) :
    stack = []
    for l in x :
        if l in ('(', '[') : stack.append(l)
        elif l in (')', ']') :
            if len(stack) == 0 : return False
            elif l == ')' and stack[-1] == '(' :
                stack.pop()
            elif l == ']' and stack[-1] == '[' :
                stack.pop()
            else : return False

    if len(stack) > 0 : return False
    else : return True

isVPS = False

while True :
    testString = input().rstrip()
    if testString == '.' : break
    isVPS = check_VPS(testString)

    if isVPS : print('yes')
    else : print('no')
