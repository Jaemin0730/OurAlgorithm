import sys
input = sys.stdin.readline

def binary_search(arr, aim):
    start = 0
    end = len(arr) - 1
    while end - start > 1:
        mid = (start + end) // 2
        if arr[mid] < aim:
            start = mid
        elif arr[mid] > aim:
            end = mid
        else:
            lis[mid] = aim
            return
    lis[end] = aim


a = int(input())
ls = list(map(int, input().split()))
lis = [0, ls[0]]

# print(lis)
for i in range(1, a):
    if ls[i] > lis[-1]:
        lis.append(ls[i])
    else:
        # 값이 어디 사이에 위치하는지 찾는다
        # 그리고 대체한다.
        binary_search(lis, ls[i])
    # print(lis)
print(len(lis) - 1)