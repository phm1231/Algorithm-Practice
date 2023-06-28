// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define ll long long
#define MAX 100001
// 0이면 빈칸이고 1이면 벽이다.

void init();
void input();
void solve();

int n;
vector<vector<int> > board(18, vector<int>(18, 0));
int dp[18][18][3]; // dp[i][j][k] = 끝 위치가 i, j에 도착했을 때, k방식으로 진입함.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    // 처음에는 (1,2)에 가로로 놓여있다.
    dp[1][2][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            // i, j로부터 i, j+1로 진입한다면 (가로)
            if(board[i][j+1] != 1) dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2];
            // i, j로부터 i+1, j로 진입한다면 (세로)
            if(board[i+1][j] != 1) dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
            // i, j로부터 i+1, j+1로 진입한다면 (대각선)
            if(board[i+1][j+1] != 1 && board[i+1][j] != 1 && board[i][j+1] != 1) dp[i+1][j+1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
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