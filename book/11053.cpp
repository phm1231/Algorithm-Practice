// based problem: dp, LIS
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
#define MAX 1001

using namespace std;

void init();
void input();
void solve();

int n;
int sequence[MAX];
int dp[MAX];

void init()
{
    memset(dp, 0, sizeof(dp));
    memset(sequence, 0, sizeof(sequence));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &sequence[i]);
    }
}

void solve()
{
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int minimum = 0;
        for(int j=1; j<=i; j++)
        {
            if(sequence[i] > sequence[j])
            {
                minimum = max(dp[j], minimum);
            }
        }
        dp[i] = minimum + 1;
        ans = max(dp[i], ans);
    }
    printf("%d", ans);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}