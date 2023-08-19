import sys
input = sys.stdin.readline

N = int(input()) # 자료구조의 개수

A = list(map(int, input().split())) 
# 길이 N의 수열 A
# 0이면 queue, 1이면 stack

B = list(map(int, input().split()))
# i번 자료구조에 들어있는 원소

M = int(input()) # 삽입할 수열의 길이

C = list(map(int, input().split())) 
# queuestack에 삽입할 원소를 담고 있는 길이 M의 수열


B_prime = [B[k] for k in range(N) if A[k] == 0] # queue인 원소만 들어간 리스트

B = B_prime[-1::-1] + C

for b in range(0, M) :
    print(B[b], end = ' ')
