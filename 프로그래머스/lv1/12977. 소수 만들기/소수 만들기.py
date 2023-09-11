import math

def solution(nums):
    answer = 0
    
    # 에라토스테네스의 체
    table = [i for i in range(3000)]
    table[1] = 0
    for i in range(2, int(math.sqrt(len(table))+1)) :
        if table[i] == 0 : continue
        for k in range(i**2, len(table), i) :
            if table[k] == 0 : continue
            table[k] = 0

    for a in range(len(nums)-2) :
        for b in range(a+1, len(nums)-1) :
            for c in range(b+1, len(nums)) :
                if table[nums[a] + nums[b] + nums[c]] != 0 :
                    answer += 1
    
    return answer