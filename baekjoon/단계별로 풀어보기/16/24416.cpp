// based problem:
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
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int n;
int dp[41];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, 0, sizeof(dp));
}

void input()
{
    cin >> n;
}

void solve()
{
    dp[0] = 0;
    dp[1] = 1; // 1
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[n] << ' ' << n-2;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}