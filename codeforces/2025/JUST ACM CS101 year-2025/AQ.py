nums = list(map(int, input().split()))
while len(nums) < nums[0] + 1:
    nums += list(map(int, input().split()))

n = nums[0]
a = nums[1:]

moves = 0

for i in range(1, n):
    while a[i] <= a[i - 1]:
        a[i] *= 2
        moves += 1

print(moves)
