def solution(sides):
    answer = 0
    sides.sort()
    line = set()
    longer = sides[1]
    # 가장 긴 변이 longer인 경우
    for k in range(longer-sides[0]+1, longer+1):
        line.add(k)
    
    # 가장 긴 변이 sides외 나머지 한 변인 경우
    for k in range(sum(sides)-1, longer, -1):
        line.add(k)
        
    answer = len(line)
    return answer