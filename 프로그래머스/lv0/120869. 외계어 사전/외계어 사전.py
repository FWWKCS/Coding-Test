def solution(spell, dic):
    answer = 2
    for d in dic :
        checked = set() # 확인된 문자
        dc = 0 # 문자 포함 증가량
        for l in d :
            if l in spell and l not in checked : 
                checked.add(l)
                dc += 1
                
        if dc == len(spell) : answer = 1
        
    return answer