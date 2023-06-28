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
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        coins.push_back(tmp);
    }
}

void solve()
{
    vector<int> dp(k+1, 0);

    // 0개의 동전을 가지고 0원을 만들 수 있다.
    dp[0] = 1;

    // 매 코인마다
    for(int coin: coins){
        
        for(int j=coin; j<=k; j++){
            dp[j] += dp[j-coin];
        }
    }
    cout << dp[k] << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}