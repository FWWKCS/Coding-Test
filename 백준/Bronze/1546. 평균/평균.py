count = int(input())
maximumScore = 0
sum = 0

subject = list(map(int,input().split()))

for i in range(count):
    maximumScore = max(subject)
    sum += (subject[i]/maximumScore)*100

print(sum/count)