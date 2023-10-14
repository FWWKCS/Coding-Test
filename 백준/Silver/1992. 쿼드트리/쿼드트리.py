import sys
input = sys.stdin.readline

def quad_tree(length, row, col) :
    if length == 1 : return
    global ziped
    tmp = '' # length = 2 일때 0과 1의 값을 생성
        
    is_zero = False
    is_one = False
    split = False
  
    for r in range(row, row+length) :
        for c in range(col, col+length) :
            if (table[r][c] == 0 and is_one) or (table[r][c] == 1 and is_zero) :
                # length > 2이면, 사분면 분열
                if length > 2 :
                    split = True
                    break
                    
            if table[r][c] == 0 : is_zero = True
            elif table[r][c] == 1 : is_one = True

            if length == 2 : tmp += str(table[r][c])

        if split : break

    # 반복문을 분열없이 모두 검사했다면
    if not split or length == 2 :
        if is_zero and (not is_one) : # 0만 있다면
            ziped += '0'
            return
        elif is_one and (not is_zero) : # 1만 있다면
            ziped += '1'
            return
        else : # 0과 1 모두 있는 경우
            ziped += '('+tmp+')'
            return
    else :
        ziped += '('

        # 2사분면
        quad_tree(length//2, row, col)
        # 1사분면
        quad_tree(length//2, row, col+length//2)
        # 3사분면
        quad_tree(length//2, row+length//2, col)
        # 4사분면
        quad_tree(length//2, row+length//2, col+length//2)

        ziped += ')' # 최종 괄호 닫기


N = int(input())
table = [list(map(int, input().rstrip())) for _ in range(N)]
ziped = ''

if N > 1:
    quad_tree(N, 0, 0)
else :
    ziped = table[0][0]
print(ziped)