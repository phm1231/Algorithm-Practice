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
vector<int> vip;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    vip.resize(m, 0);
    for(int i=0; i<m; i++){
        cin >> vip[i];
    }
}

void solve()
{
    vector<ll> dp(41, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=40; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    vector<int> gaps;
    for(int i=0; i<m; i++){
        if(i == 0) gaps.push_back(vip[i] - 1);
        else gaps.push_back(vip[i] - vip[i-1] - 1);
    }
    if(m != 0 && n != vip.back()) gaps.push_back(n - vip.back());

    // vip가 없음
    if(m == 0){
        cout << dp[n];
        return;
    }
    ll answer = 1;
    for(int gap: gaps){
        answer *= dp[gap];
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}