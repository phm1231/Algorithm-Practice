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
vector<int> coins;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    coins.resize(n, 0);
    for(int i=0; i<n; i++) cin >> coins[i];
}

void solve()
{
    vector<int> dp(k+1, 987654321);
    // dp[i] = i원을 만드는데 필요한 동전의 최소 개수
    dp[0] = 0;

    for(int coin: coins){
        dp[coin] = 1;
        for(int j=coin; j<=k; j++){
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }
    if(dp[k] != 987654321) cout << dp[k];
    else cout << -1;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}