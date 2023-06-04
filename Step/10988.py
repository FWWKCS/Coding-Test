# https://www.acmicpc.net/problem/10988

# 팰린드롬

# 첫째 줄에 단어가 주어진다. 
# 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 
# 알파벳 소문자로만 이루어져 있다.

input = input()

# print(len(input)//2, input[len(input)//2])

result = 1

for i in range(len(input)//2):
    if input[i] == input[len(input)-i-1] : continue
    else : 
        result = 0
        break

print(result)
