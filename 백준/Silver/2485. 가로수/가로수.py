def get_GCD (v0, v1) :
    if v1 == 0 : return v0
    return get_GCD(v1, v0%v1)

count = int(input())

data = []

distance = []

extra = 0

for _ in range(count) :
    data.append(int(input()))

if count > 2 :
    # 각 나무의 거리 계산
    for d in range(1, len(data)) :
        distance.append(data[d]-data[d-1])

    distance = sorted(set(distance))

    # 리스트에서 남은 작은 두 서로소의 최대공약수가 필요 거리
    if len(distance) > 1 :
        # 모든 수의 최대공약수를 구하기
        foundDistance = get_GCD(distance[0], distance[1])
        for k in range(2, len(distance)) :
            foundDistance = get_GCD(foundDistance, distance[k]) 

        # 최대공약수 값으로 나눈 데이터간의 차 만큼 더 나무를 심음
        for d in range(1, len(data)) :
            extra += ((data[d]-data[d-1]) // foundDistance) -1

# 데이터 개수가 1, 2이거나, 거리 계산시 모든 나무가 이미 균등하게 위치해있는 경우 0을 출력
print(extra)