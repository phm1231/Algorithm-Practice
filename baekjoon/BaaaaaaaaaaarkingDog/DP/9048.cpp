#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, m;
vector<int> coins;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    coins.clear();
    for(int i=0; i<n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    cin >> m;
}

void solve()
{
    int dp[10001] = {0, };
    dp[0] = 1; // 0원을 만드는 방법의 가짓수.
    for(int coin: coins){
        for(int j=coin; j<=m; j++){
            dp[j] += dp[j-coin];
        }
    }
    cout << dp[m] << endl;
}


int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}