# https://www.acmicpc.net/problem/1316

# 각 문자가 연속으로 나타나는 경우만 존재하는 단어

# happy는 h, a, p, y가 그룹으로 묶여있으므로 그룹단어
# accumulate는 a, u가 연속으로 존재하지 않으므로 그룹단어가 아님

# 그룹단어 필요조건
# 

def checkGrouped(word):
    # 각 같은 문자가 확인되면 
    checked = []
    checked.append(word[0])
    for w in range(1,len(word)):
        if word[w] not in checked : checked.append(word[w])
        elif word[w] in checked and word[w] == word[w-1] : continue
        else : 
            # print(f"{word}의 {word[w]}에서 그룹 단어가 아님을 검출했습니다")
            return False

    return True

count = int(input())

groupWords = 0
for _ in range(count):
    word = input()
    grouped = checkGrouped(word)
    if grouped == True : groupWords += 1

print(groupWords)