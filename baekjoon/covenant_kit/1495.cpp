// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, s, m;
// 곡의 개수, 시작 볼륨, 바꿀 수 있는 최댓값
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> s >> m;
    v.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> v[i];
}

void solve()
{
    // dp[i][j] = i번째 곡일 때 볼륨 j 가능 여부
    vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
    dp[0][s] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(!dp[i-1][j]) continue;
            if(j - v[i] >= 0) dp[i][j-v[i]] = true;
            if(j + v[i] <= m) dp[i][j+v[i]] = true;
        }
    }

    for(int j=m; j>=0; j--){
        if(dp[n][j]){
            cout << j;
            return;
        }
    }
    cout << -1;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}