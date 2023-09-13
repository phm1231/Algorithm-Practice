#include <iostream>
#include <vector>

#define ll long long
#define MAX 1000000009
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
   vector<ll> dp(1000001, 0);
   dp[1] = 1;
   dp[2] = 2;
   dp[3] = 4;

    for(int i=4; i<=1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MAX;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    
}


int main()
{
    init();
    input();
    solve();
    return 0;
}