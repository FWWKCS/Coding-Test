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