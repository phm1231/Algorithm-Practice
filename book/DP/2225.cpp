// based problem: dp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>

#define ll long long
#define MAX 201
#define MOD 1000000000

using namespace std;

void init();
void input();
void solve();

int n, k;
ll dp[MAX][MAX]; // dp[i] 는 i까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수의 합.

void init()
{
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%d %d", &n, &k);
}

void solve()
{
    for(int i=1; i<=k; i++)
    {
        dp[1][i] = i % MOD;
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=k; j++) // for sum
        {
            ll dpsum = 0;
            for(int idx=1; idx<=j; idx++)
            {
                dpsum += dp[i-1][idx] % MOD;
            }
            dp[i][j] = dpsum % MOD;
        }
    }

    printf("%lld", dp[n][k] % MOD);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}