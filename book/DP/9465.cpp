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
#define MAX 100001

using namespace std;

void init();
void input();
void solve();

int t, n;
int score[2][MAX];
int dp[2][MAX];

void init()
{
    memset(dp, 0, sizeof(dp));
    memset(score, 0, sizeof(score));
}

void input()
{
    scanf("%d", &n); 
    for(int i=0; i<=1; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &score[i][j]);
        }
    }

    dp[0][0] = score[0][0]; // 0
    dp[1][0] = score[1][0];

    dp[0][1] = dp[1][0] + score[0][1];
    dp[1][1] = dp[0][0] + score[1][1];
}

void solve()
{
    for(int i=2; i<=n; i++)
    {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + score[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + score[1][i];
    }
    printf("%d\n", max(dp[0][n], dp[1][n]));
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        input();
        solve();
    }
    return 0;
}