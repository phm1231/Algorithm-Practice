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
#define MAX 301

using namespace std;

void init();
void input();
void solve();

int n;
int floor[MAX];
int dp[MAX];

void init()
{
    memset(floor, 0, sizeof(floor));
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &floor[i]);
    }
}

void solve()
{
    dp[1] = floor[1];
    dp[2] = floor[1] + floor[2];
    for(int i=3; i<=n; i++)
    {
        dp[i] = max(dp[i-2] + floor[i], dp[i-3] + floor[i-1] + floor[i]);
        // dp[i] = max(dp[i-1], dp[i]): 고른다.
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