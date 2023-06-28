count, quiz = map(int,input().split())

collection = {
    # 딕셔너리
}

answer = []

for i in range(count) :
    data = input()
    collection[i+1] = data
    collection[data] = i+1

# 문제 시작
for _ in range(quiz) :
    data = input()
    # str.isdigit()
    # 문자열이 숫자로만 이루어져있는지 확인하는 함수
    if data.isdigit() :
        answer.append(collection[int(data)])
    else :
        answer.append(collection[data])

for a in answer :
    print(a)