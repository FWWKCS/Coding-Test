nums = list(map(str,input().split()))

for i in range(2):
    nums[i] = int(nums[i][::-1])

print(max(nums))