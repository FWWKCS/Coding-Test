N, K = map(int, input().split())

rank = 1
medal = {
    # tuple(gold, silver, bronze) : { countries }
}

for _ in range(N) :
    country, gold, silver, bronze = map(int, input().split())
    if (gold, silver, bronze) in medal : medal[(gold, silver, bronze)].add(country)
    else :
        medal[(gold, silver, bronze)] = {country}

arr = sorted(list(medal.keys()), key = lambda x : (x[0], x[1], x[2]), reverse = True)

index = 0
while K not in medal[arr[index]] :
    index += 1
    rank += len(medal[arr[index]])

print(rank)