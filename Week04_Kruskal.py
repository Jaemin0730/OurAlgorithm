n = input()
D = [[]]  # 선분의 가중치를 저장한 리스트
# 출력: 모든 쌍 최단 경로의 거리를 저장한 2-d배열 D
def all_pairs_shortest(D):
    for k in range(n):  # 경유
        for i in range(n):  # i와 j를 모두 탐색하여 최솟값을 발견 (n^2)
            for j in range(n):
                if i == j:
                    continue
                if D[i][j] > D[i][k] + D[k][j]:
                    D[i][j] = D[i][k] + D[k][j]