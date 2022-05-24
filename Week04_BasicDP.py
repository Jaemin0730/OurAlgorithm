a = []  # 수열
n = input()
LIS = []  # 기록
for i in range(1, n + 1):
    for j in range(1, i):
        if a[j] < a[i] and 1 + LIS[j] > LIS[i]:
            LIS[i] = 1 + LIS[j]
print(max(LIS))