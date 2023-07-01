// based problem:
#include <iostream>
#include <vector>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    vector<ll> dp(n+1, 0);
    // 그냥 찍기.
    for(int i=1; i<=n; i++) dp[i] = dp[i] = i;

    // 복사해서 계속 찍기
    for(int i=4; i<=n; i++){
        ll buffer = dp[i-3];
        for(int j=i; j<=n; j++){
            dp[j] = max(dp[j], dp[i-3] + buffer * (j-i + 1));
        }
    }

    cout << dp[n];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}