def solution(cards):

    # 그룹 생성
    group = []
    visited = set() # 이미 그룹에 속해있는 카드 확인
    
    for i in range(len(cards)) :
        if cards[i] in visited : continue
        
        startIndex = i+1
        # 시작점의 카드번호
        current = cards[i]
        visited.add(current)
        semiGroup = 1
        
        while True :
            if current == startIndex : break
            
            index = current-1
            current = cards[index]
            semiGroup += 1
            visited.add(current)
        
        group.append(semiGroup)
        
    group.sort()
    
    if len(group) > 1 :
        return group[-1] * group[-2]
    else : return 0