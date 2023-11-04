import collections
import sys
input = sys.stdin.readline

MOD = 10000
T = int(input())
for _ in range(T):
    value, target = input().split()
    target = int(target)

    visited = {int(value)}

    command = ''
    command_length = float('inf') # 커맨드 길이

    queue = collections.deque([(value, command, 0)]) # (현재 숫자, 명령 상태, 현재 명령의 길이)

    while queue:
        current, order, length = queue.popleft()
        current = int(current)
        length = int(length)

        if length > command_length : continue

        if current == target:
            if length < command_length:
                command_length = length
                command = order

        # D (2n mod 10000)
        result = (2*current) % MOD
        if result not in visited:
            queue.append((result, order+'D', length+1))
            if result != target :
                visited.add(result)
        # S (n-1)
        result = (current - 1) if current - 1 != -1 else 9999
        if result not in visited:
            queue.append((result, order+'S', length+1))
            if result != target :
                visited.add(result)
        # L (L-shift)
        result = current * 10
        result = (result % MOD) + (result // MOD)
        if result not in visited:
           queue.append((result, order+'L', length+1))
           if result != target :
                visited.add(result)
        # R (R-shift)
        result = ((current % 10) * 1000) + (current // 10)
        if result not in visited:
            queue.append((result, order+'R', length+1))
            if result != target :
                visited.add(result)

    print(command)