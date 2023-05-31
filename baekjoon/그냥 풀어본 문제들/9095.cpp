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
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int t;
int n;

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    long long dp[11] = {0, };
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=n; i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    cout << dp[n] << "\n";
}

int main()
{
    init();
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}