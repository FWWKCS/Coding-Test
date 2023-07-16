def seperate(s) :
    # ) 이나 ( 중 하나를 시작으로 추가되고 
    # 다음 문자로 인해 두 문자의 개수 비율이 같아지면 즉시 return
    
    # 분리 지점 index를 반환
    countOpen = 0 # open '('
    countClose = 0 # close ')'
    index = 0
    for l in s : 
        if l == '(' : countOpen += 1
        else : countClose += 1

        if countOpen == countClose : return index
        index += 1


# 올바른 괄호 문자열인지 확인
def isRight(s) :
    stack = []
    for l in s :
        if l == '(' : stack.append(l)
        else :
            if len(stack) == 0 : return False
            else : stack.pop()

    if len(stack) > 0 : return False
    
    return True


def solution(w) :
    # 빈 문자열은 그대로 반환
    if w == '' : return ''
    elif isRight(w) : return w

    # 분리 중간점 연산
    index = seperate(w) 

    # 문자열 분리 (u는 최소한의 균형잡힌 괄호 문자열)
    u = w[: index + 1]
    v = w[index + 1 :]

    # v에 대해 함수 수행후 u에 이어 붙인 후 반환
    if isRight(u) : 
        return u + solution(v)
    else :
        # 빈 문자열에 첫 번째 문자로 ( 추가
        tmp = ''
        tmp += '('

        # v에 대해 재귀적으로 수행한 결과 문자열 추가
        tmp += solution(v)
        tmp += ')'

        # 첫/마지막 문자 제거, 문자 방향 반전
        u = list(u)
        del u[0]
        del u[-1]
        
        for k in range(len(u)) :
            if u[k] == ')' : u[k] = '('
            else : u[k] = ')'

        u = ''.join(u)


        # 최종 문자열 반환
        return tmp + u
    


