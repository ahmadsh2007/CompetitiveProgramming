n = 100000
# for _ in range(n):
#     print(100 - _, end=" ")

import random
# print(n)
arr = []
for _ in range(n):
    # print(_ + 1, end="\n")
    arr.append(random.randint(10**7, 10**9))

with open("output.txt", "w") as f:
    f.write("\n".join(map(str, arr)))