examinee, cutline = map(int, input().split())
score = list(map(int, input().split()))

for i in range(examinee-1):
    for j in range(i+1, examinee):
        if score[i] < score[j] :
            score[i], score[j] = score[j], score[i]
            
print(score[cutline-1])