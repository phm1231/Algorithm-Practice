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
vector<int> weights;
vector<int> values;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    weights.resize(n+1, 0);
    values.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> weights[i] >> values[i];
}

void solve()
{
    vector<vector<int> > dp(n+1, vector<int>(100001, 0));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j - weights[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
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