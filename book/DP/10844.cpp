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

#define ll long long
#define MAX 101
#define MOD 1000000000
using namespace std;

void init();
void input();
void solve();

int n;
ll dp[MAX][10];

void init()
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=9; i++)
    {
        dp[1][i] = 1;
    }
}

void input()
{
    scanf("%d", &n);
}

void solve()
{
    ll sum = 0;
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(j == 0) dp[i][j] = dp[i-1][j+1] % MOD;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % MOD;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }
    for(int i=0; i<=9; i++)
    {
        sum += dp[n][i] % MOD;
    }
    printf("%lld", sum % MOD);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}