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
#define MAX 100001

using namespace std;

void init();
void input();
void solve();

ll n;
ll dp[MAX]; // dp[n] = n을 제곱수의 합으로 나타낼 때 항의 최소 개수.

void init()
{
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%lld", &n);
}

void solve()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(ll i=4; i<=n; i++)
    {
        dp[i] = i;
        for(ll j=1; j*j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    printf("%lld", dp[n]);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}