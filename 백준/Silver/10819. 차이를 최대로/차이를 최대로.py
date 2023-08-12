def findMaximumSum(arr, visitedIndex) :
    global maximumSum
    if len(arr) == N :
        arrSum = 0
        for k in range(0,N-1) :
            arrSum += abs(arr[k] - arr[k+1])
        maximumSum = max(maximumSum, arrSum)
        return

    for k in range(N) :
        if k in visitedIndex : continue

        findMaximumSum(arr+[nums[k]], visitedIndex+[k])

N = int(input())

nums = list(map(int, input().split()))

maximumSum = 0

findMaximumSum([],[])

print(maximumSum)