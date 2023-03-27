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
int dfs(int, int);

int n;
int cnt = 0;
int board[101][101];
int dp[101][101];
// dp[i][j] = dp[i-board[i][j]][j] + dp[i][j-board[i][j]];

void init()
{
    FAST
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = board[i][j] = 0;
        }
    }
    dp[1][1] = 1;
}

void input()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] == 0) continue;
        }
    }
    cout << dp[n][n];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}