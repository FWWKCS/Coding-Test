string = list(input())

start = 0
end = 0
while end < len(string) :
    if string[end] == '<' :
        # 만약 두 지점의 위치가 다르면 반전을 먼저 진행
        if start < end :
            sliced = string[start:end]
            string[start:end] = sliced[::-1]
            # 시작점을 end로 이동
            start = end
        
        # >를 만날때까지 모두 이동
        while string[end] != '>' :
            start += 1
            end += 1
        
        # > 옆으로 이동
        start += 1
        end += 1
        continue
    
    # 공백을 기준으로 반전
    if string[end] == ' ' :
        sliced = string[start:end]
        string[start:end] = sliced[::-1]
        
        # 시작점을 end로 이동
        start = end
        start += 1
        end += 1
        continue

    end += 1

if start != end :
    # 마지막 반전
    sliced = string[start:end]
    string[start:end] = sliced[::-1]

print(''.join(string))