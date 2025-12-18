N = int(input())

times = list(map(int, input().split()))

drivers = [(times[i], i + 1) for i in range(N)]

drivers.sort()

print(" ".join(str(driver[1]) for driver in drivers))
