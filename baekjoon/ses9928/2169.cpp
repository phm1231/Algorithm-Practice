// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001
#define R_INF -987654321;

void init();
void input();
void solve();
int dfs(int, int, int);

int n, m;
vector<vector<int> > bd;
int dy[] = {0, 0, 1};
int dx[] = {-1, 1, 0};
int dp[1001][1001][3];
bool visited[1001][1001];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n+2, vector<int>(m+2, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> bd[i][j];
        }
    }

    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            visited[i][j] = false;
            for(int k=0; k<3; k++) dp[i][j][k] = R_INF;
        }
    }
}

void solve()
{
    int answer = dfs(1, 1, 0);
    cout << answer;
}

int dfs(int y, int x, int dir){
    if(y==n && x==m) return bd[y][x];
    if(dp[y][x][dir] != -987654321) return dp[y][x][dir];

    visited[y][x] = true;
    int biggest = R_INF;
    for(int i=0; i<3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(1<=ny && ny<=n && 1<=nx && nx<=m){
            if(!visited[ny][nx]) biggest = max(biggest, dfs(ny, nx, i));
        }
    }
    visited[y][x] = false;
    dp[y][x][dir] = bd[y][x] + biggest;
    return dp[y][x][dir];

}


int main()
{
    init();
    input();
    solve();
    return 0;
}