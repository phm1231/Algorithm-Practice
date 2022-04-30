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
#define MAX 10001

using namespace std;

void init();
void input();
void solve();

int n;
int amount[MAX];
int dp[MAX];

void init()
{
    memset(amount, 0, sizeof(amount));
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &amount[i]);
    }
    dp[0] = 0;
    dp[1] = amount[1];
    dp[2] = amount[1] + amount[2];
    dp[3] = max(dp[0] + amount[2] + amount[3], dp[1] + amount[3]);
    dp[3] = max(dp[2], dp[3]);
}

void solve()
{
    for(int i=4; i<=n; i++)
    {
        dp[i] = max(dp[i-3] + amount[i-1] + amount[i], dp[i-2] + amount[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }
    printf("%d", dp[n]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}