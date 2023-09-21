import sys
input = sys.stdin.readline

L = int(input())
string = input().rstrip()

hash_value = 0
for l in range(L) :
    hash_value += (ord(string[l])-96) * (31 ** l)

hash_value %= 1234567891

print(hash_value)