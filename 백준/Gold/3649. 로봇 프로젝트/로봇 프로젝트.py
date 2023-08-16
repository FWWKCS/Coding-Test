import sys
input = sys.stdin.readline

def binary_search(lego, findValue, selectedIndex) :
    start = 0
    end = len(lego) - 1

    while start <= end :
        pivot = (start+end) // 2
        if lego[pivot] == findValue and pivot != selectedIndex : return pivot
        elif lego[pivot] > findValue : end = pivot - 1
        else : start = pivot + 1

    return -1

while True :
    try :
        x = int(input().rstrip()) * 10000000 # 나노미터 단위화 100000000
    except : break

    n = int(input())
    lego = []
    for _ in range(n) :
        lego.append(int(input()))

    possible = False # 1차 필터링, 분석 가능여부
    success = False # 분석 결과
    found = []

    if n >= 2 : possible = True

    if possible :
        lego.sort()

        for k in range(len(lego)) :
            index = binary_search(lego, x-lego[k], k)

            if index > -1 : 
                success = True
                found = [lego[k], lego[index]]
                break

        if success :
            print(f'yes {found[0]} {found[1]}')
        else : 
            print('danger')

    # 블럭이 2개 미만일때
    else : print('danger')
