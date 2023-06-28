// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int dy[] = {0, 1};
int dx[] = {1, 0};
int n;
vector<vector<int> > board;
vector<vector<ll> > dp;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    dp.resize(n, vector<ll>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    dp[0][0] = 1;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(board[y][x] != 0){
                int w = board[y][x];
                for(int i=0; i<2; i++){
                    int ny = y + dy[i] * w;
                    int nx = x + dx[i] * w;
                    if(0 <= ny && ny < n && 0 <= nx && nx < n){
                        dp[ny][nx] += dp[y][x];
                    }
                }
            }
        }
    }

    cout << dp[n-1][n-1];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}