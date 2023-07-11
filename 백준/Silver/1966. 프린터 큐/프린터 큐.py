import collections
import sys
input = sys.stdin.readline

testCase = int(input())

for _ in range(testCase) :
    docCount, targetIndex = (map(int,input().split())) 
    # 문서의 개수, 목표 문서의 초기 위치
    queue = collections.deque(map(int, input().split())) # 우선순위로 표기된 문서
    
    priority = 0 # 문서가 하나씩 출력될 때마다 값이 증가 ( 목표문서가 출력되면 그때의 값을 출력)
    currentMax = max(queue) # 초기 queue의 우선순위 최댓값

    while True :
        # 0번째 문서가 최대 우선순위인지 확인
        # Y : 내가 지정한 문서(targetIndex)가 현재 0번째 인덱스(출력 대상)인가?
        #   Y : priority 1증가 후 반복문 탈출(답 출력)
        #   N : priority 1증가 및 targetIndex 1감소, currentMax 변화가 있으면 currentMax 초기화
        # N : 내가 지정한 문서(targetIndex)가 현재 0번째 인덱스인가?
        #   Y : 마지막 인덱스값으로 지정
        #   N : targetIndex 1감소
        if queue[0] == currentMax :
            if targetIndex == 0 :
                queue.popleft()
                priority += 1
                break
            else :
                queue.popleft()
                priority += 1
                targetIndex -= 1
                if max(queue) != currentMax : currentMax = max(queue)
        else :
            if targetIndex == 0 :
                queue.rotate(-1)
                targetIndex = len(queue) - 1
            else :
                queue.rotate(-1)
                targetIndex -= 1
    
    print(priority)