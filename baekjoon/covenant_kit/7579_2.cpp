// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<int> costs;
vector<int> memories;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    costs.resize(n+1, 0);
    memories.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> memories[i];
    for(int i=1; i<=n; i++) cin >> costs[i];
}

void solve()
{
    vector<vector<int> > dp(101, vector<int>(10001, 0));
    for(int i=1; i<=n; i++) dp[i][costs[i]] = memories[i];
    for(int i=1; i<=n; i++){
        for(int j=0; j<10001; j++){
            if(j - costs[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i]] + memories[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0; i<10001; i++){
        if(dp[n][i] >= m){
            cout << i;
            return;
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}