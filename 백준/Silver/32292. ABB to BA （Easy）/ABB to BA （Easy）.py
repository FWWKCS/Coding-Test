import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().rstrip()
    while(s.find("ABB") != -1):
        s = s.replace("ABB", "BA")

    print(s)