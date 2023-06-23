input = input()

foundAry = [[],[]] # [문자 종류],[각 문자 카운트]

for ch in input:
    if ch in foundAry[0] or ch.lower() in foundAry[0] : continue
    foundAry[0].append(ch.lower())
    foundAry[1].append(0)


for ch in input:
    index = foundAry[0].index(ch.lower())
    foundAry[1][index] += 1

maxIndex = []
for t in foundAry[1]:
    if t == max(foundAry[1]) :
        maxIndex.append(foundAry[1].index(t))

if len(maxIndex) != 1 : print("?")
else : print(foundAry[0][maxIndex[0]].upper())