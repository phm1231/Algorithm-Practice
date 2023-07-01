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
string board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    cin >> board;   
}

void solve()
{
    vector<ll> dp(n, 987654321);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        char cur = board[i];
        for(int j=i+1; j<n; j++){
            ll gap = j-i;
            if(cur == 'B' && board[j] == 'O'){
                dp[j] = min(dp[j], dp[i] + (gap*gap));
                continue;
            }
            if(cur == 'O' && board[j] == 'J'){
                dp[j] = min(dp[j], dp[i] + (gap*gap));
                continue;
            }
            if(cur == 'J' && board[j] == 'B'){
                dp[j] = min(dp[j], dp[i] + (gap*gap));
                continue;
            }
        }
    }
    if(dp[n-1] == 987654321) cout << -1;
    else cout << dp[n-1];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}