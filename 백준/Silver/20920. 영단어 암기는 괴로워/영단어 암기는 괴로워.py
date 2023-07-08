import sys
input = sys.stdin.readline

words, length = map(int, input().split())

wordDict = {
    # 단어 : 빈도
}

memorize = []

for _ in range(words) :
    word = input().rstrip()
    if len(word) >= length :
        if word in wordDict : wordDict[word] += 1
        else : wordDict[word] = 1

# 빈도수별로 분할해서 재정렬
for f in range(max(wordDict.values()), 0, -1) :
    tmp = [k for k,v in wordDict.items() if v == f]
    # 빈도 순 -> 길이 순 -> 알파벳 사전 순
    tmp = sorted(tmp, key = lambda x : (-len(x), x))
    memorize += tmp

for m in memorize : print(m)