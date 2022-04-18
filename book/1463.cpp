// based problem: DP

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
#define MAX 1000001

using namespace std;

void init();
void input();
void solve();

int n;
int dp[MAX];

void init()
{
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%d", &n);
}

void solve()
{
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
    }
    printf("%d\n", dp[n]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}