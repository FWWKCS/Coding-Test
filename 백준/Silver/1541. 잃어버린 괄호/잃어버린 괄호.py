expression = input()

total = 0 

# 앞에서부터 문자열 순회

# -를 발견하면 괄호연산 시작
    # +를 발견하면 가산
    # -를 발견하면 지금까지의 합산을 총합에 감산

index = 0
tmp_string = '0'
minus = False

while index != len(expression) :
    l = expression[index]

    if not minus :
        if l == '-' :
            total += int(tmp_string)
            tmp_string = '0'
            minus = True
        elif l == '+' :
            total += int(tmp_string)
            tmp_string = '0'
        else :
            tmp_string += l
    else :
        if l == '-' or l == '+' :
            total -= int(tmp_string)
            tmp_string = '0'
        else :
            tmp_string += l
    

    if index == len(expression) -1 :
        if minus :
            total -= int(tmp_string)
        else :
            total += int(tmp_string)

    index += 1
    
print(total)