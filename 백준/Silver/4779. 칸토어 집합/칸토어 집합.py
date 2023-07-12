def Cantor(string) :
    if len(string) == 1 : return '-'

    start = len(string) // 3  # 제거할 영역 시작점 인덱스
    end = ( (len(string) // 3 ) * 2 ) - 1 # 제거할 영역 종점 인덱스
    string = list(string) # 문자열 수정을 위한 형변환
    for i in range(start, end+1) : string[i] = ' '
    string = ''.join(string) 

    mid = string[start:end+1]
    L = Cantor(string[:start])
    R = Cantor(string[end+1:])

    return L + mid + R

while True :
    try :
        N = int(input())
    except : # EOF Error
        break

    size = 3 ** N
    string = '-' * size

    print(Cantor(string))

