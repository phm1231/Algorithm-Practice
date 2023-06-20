// based problem:
#include <vector>
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n;
vector<vector<int> > prices(1001, vector<int>(3, 0));
vector<vector<int> > dp(1001, vector<int>(3, 987654321));

void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> prices[i][j];
        }
    }
}

void solve()
{
    dp[0][0] = prices[0][0];
    dp[0][1] = prices[0][1];
    dp[0][2] = prices[0][2];

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1] + prices[i][0], dp[i-1][2] + prices[i][0]);
        dp[i][1] = min(dp[i-1][0] + prices[i][1], dp[i-1][2] + prices[i][1]);
        dp[i][2] = min(dp[i-1][0] + prices[i][2], dp[i-1][1] + prices[i][2]);
    }

    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

int main()
{
    init();
    input();
    solve();
    return 0;
}