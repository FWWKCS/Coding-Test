def solution(s):
    answer = True
    stack = []
    for c in s :
        if c == "(" : stack.append('(')
        elif stack and c == ')' :
            stack.pop()
        else :
            answer = False
            break
    
    if stack : answer = False

    return answer