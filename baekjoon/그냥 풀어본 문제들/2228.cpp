// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

int n, m;
vector<int> v;
vector<int> sums;

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
    v.resize(n+1, 0);
    sums.resize(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> v[i];
        if(i == 1) sums[i] = v[i];
        else sums[i] = sums[i-1] + v[i]; 
    }
}

void solve()
{
    vector<vector<int> > dp(n, vector<int>(m+1, -987654321));// dp[i][j] = i개의 수를 j개의 구간으로 나누었을 때 최대 합.

    for(int i=1; i<n; i++){ // i번째 까지의 수
        for(int j=1; j<=m; j++){ // j개의 구간
            dp[i][j] = dp[i-1][j]; // i번째 수가 구간 j에 포함되지 않은 경우
            for(int k=1; k<=i; k++){

            }
        }
    }
    cout << dp[n][m];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}