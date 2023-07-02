// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, k;
vector<int> w;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    w.resize(n+1, 0);
    v.resize(n+1, 0);

    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
}  

void solve()
{
    // 배낭에 넣을 수 있는 물건들의 가치의 최댓값
    // n = 물건의 개수, k = 무게
    // 최대 개수는 100, 최대 무게는 100000
    // dp[i][j] = 최대 무게가 j인 가방에서 i번째 물건까지 판단했을 때의 최대 가치.
    vector<vector<int> > dp(n+1, vector<int>(100001, 0));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j - w[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}