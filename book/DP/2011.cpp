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
#define MAX 5001
#define MOD 1000000

using namespace std;

void init();
void input();
void solve();

char num_str[MAX];
ll dp[MAX]; // dp[i]는 num_str[i]까지 읽었을 때 해석할 수 있는 가짓수.
int len;

void init()
{
    memset(dp, 0, sizeof(dp));
    memset(num_str, 0, sizeof(num_str));
}

void input()
{
    scanf("%s", num_str);
}

void solve()
{
    dp[0] = dp[1] = 1;
    len = strlen(num_str);
    for(int i=2; i<=len; i++)
    {
        int nowidx = i - 1;
        int num;
        int a = num_str[nowidx - 1] - '0';
        int b = num_str[nowidx] - '0';

        if(a == 0 && b == 0)
        {
            printf("0");
            return;
        }
        if(b > 0)
        {
            dp[i] += dp[i-1] % MOD;
        }
        num = a * 10 + b;
        if(10 <= num && num <= 26)
        {
            dp[i] += dp[i-2] % MOD;
        }
        dp[i] %= MOD;
    }
    printf("%lld", dp[len]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}