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
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=4; i++) dp[i] = i;
    for(int i=5; i<=n; i++){
        if(i % 3 == 0 || i % 2 == 0) dp[i] = dp[i-1] + 2;
        else dp[i] = dp[i-1] + 1;
    }
    cout << dp[n] << endl;
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