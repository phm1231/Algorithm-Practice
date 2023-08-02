// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int dfs(int, int);

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > dp;
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(m, 0));
    dp.resize(n, vector<int>(m, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    dfs(0, 0);
    cout << dp[0][0];
}

int dfs(int y, int x){
    if(y == n-1 && x == m-1) return 1;
    if(dp[y][x] != -1) return dp[y][x]; // 이미 방문한 적이 있다면.

    dp[y][x] = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(bd[y][x] > bd[ny][nx]){
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}