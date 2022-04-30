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
#define MAX 31

using namespace std;

void init();
void input();
void solve();

int n;
ll dp[MAX];
int newface[MAX];

void init()
{
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<MAX; i++) newface[i] = 2;
}

void input()
{
    scanf("%d", &n);
}

void solve()
{
    if (n % 2 == 1)
    {
        printf("0");
    }
    else
    {
        dp[0] = 0;
        dp[2] = 3;
        newface[2] = 3;
        for(int i=4; i<=n; i+=2)
        {
            for(int j=2; j<=i; j+=2)
            {
                dp[i] += dp[i-j] * newface[j];
            }
            dp[i] += 2;
        }
        printf("%d", dp[n]);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}