// based problem:
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<vector<int> > bd;
int dp[17][17][3];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    bd.resize(n+1, vector<int>(n+1, 0));
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    dp[1][2][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(bd[i][j] == 1) continue;

            // 위에서 올 수 있음
            if(bd[i-1][j] == 0){
                dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
            }
            // 좌측에서 올 수 있음
            if(bd[i][j-1] == 0){
                dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];
            }
            // 대각선에서 올 수 있음
            if(bd[i-1][j-1] == 0 && bd[i-1][j] == 0 && bd[i][j-1] == 0){
                dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}