// 제곱연산(재귀)

int recursivePower(int x, int n)
{
   if (n == 0) return 1;  // base case1
   if (n == 1)   return x;  // base case2

   return x * recursivePower(x, n - 1);
}

// 제곱연산(반복)

int iterativePower(int x, int n)
{
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= x;
    return ret;
}

// TSP 해결
#include<iostream>
#include<stdio.h>
using namespace std;
#define INF 987654321
#define MAX_N 6

int N, Graph[MAX_N][MAX_N];
int solve(int pos, int visited);  // pos에서 visited로 가는 비용을 반환
int main()
{
    int tcCnt;
    freopen("tsp_input.txt", "r", stdin);
    cin >> tcCnt;
    for (int t = 1; t <= tcCnt; t++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Graph[i][j];
            }
        }
        int ans = INF;
        for (int i = 0; i < N; i++)
        {
            int tmp = solve(i, 1 << i);
            if (ans > tmp)
            {
                ans = tmp;
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}

int solve(int pos, int visited)
{
   // 모든 Bit가 켜져있는 경우(전부 방문했을 때) 종료
   if (visited == (1 << N) - 1)  // 10000 -> 1111
    {
        return 0;
    }
    int ret = INF;
    for (int next = 0; next < N; next++)
    {
    // 갔던 곳을 재방문 하지 않도록 하는 선택부분 && 길이 존재하는가?
        if (!(visited & (1 << next)) && Graph[pos][next])
        {
            // 다음 도시를 방문하는데 필요한 비용, 여기서 solve()의 두번째 인수는 방문을 의미
            // 01 | 10 -> 11이라면 지금 1번째를 돌고 있고 다음으로 갈곳은 2번째이므로
            // 다음으로 실행될 solve()는 1번과 2번을 재방문해서는 안된다.
            int tmp = Graph[pos][next] + solve(next, visited | (1 << next));
            // 최솟값 갱신
            if (tmp < ret)
            {
                ret = tmp;
            }
        }
    }
    return ret;
}