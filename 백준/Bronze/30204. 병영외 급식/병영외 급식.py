import sys
input = sys.stdin.readline

N, X = map(int, input().split())
team = list(map(int, input().split()))

if sum(team) % X == 0 : print(1)
else : print(0)