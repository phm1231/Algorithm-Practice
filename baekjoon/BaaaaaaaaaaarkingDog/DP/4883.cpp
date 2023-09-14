#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int t, n;
int bd[100001][3] = {0, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    memset(bd, 0, sizeof(bd));

    for(int i=1; i<=n; i++){
        cin >> bd[i][0] >> bd[i][1] >> bd[i][2];
    }
}

void solve()
{
    ll dp[100001][3];
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = 987654321;
        }
    }

    dp[1][1] = bd[1][1];
    dp[1][2] = bd[1][1] + bd[1][2];

    // 행
    for(int i=2; i<=n; i++){
        // 열
        for(int j=0; j<3; j++){
            // 위에서 오는 것
            dp[i][j] = min(dp[i-1][j] + bd[i][j], dp[i][j]);
            // 옆에서 오는 것
            if(j-1 >= 0) dp[i][j] = min(dp[i][j-1] + bd[i][j], dp[i][j]);
            // 대각선에서 오는 것
            if(j-1 >= 0) dp[i][j] = min(dp[i-1][j-1] + bd[i][j], dp[i][j]);
            if(j+1 <= 2) dp[i][j] = min(dp[i-1][j+1] + bd[i][j], dp[i][j]);
        }
    }

    cout << t << ". " << dp[n][1] << endl;
}


int main()
{
    init();
    for(t=1; ; t++){
        cin >> n;
        if(n == 0) break;
        input();
        solve();
    }
    return 0;
}