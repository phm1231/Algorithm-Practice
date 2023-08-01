// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int y, int x, int sum, int depth);
void getT(int y, int x);
int n, m, tmp;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > bd;
vector<vector<int> > sums;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(m, 0));
    sums.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    int a1, a2;
    a1 = a2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            tmp = 0;
            dfs(i, j, 0, 0);
            visited[i][j] = false;
            getT(i, j);
            sums[i][j] = tmp;
            a1 = max(a1, tmp);
        }
    }
    cout << answer;
}

void dfs(int y, int x, int sum, int depth){
    if(depth == 4){
        tmp = max(tmp, sum);
        return;
    }
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(!visited[ny][nx]){
                visited[ny][nx] = true;
                dfs(ny, nx, sum + bd[ny][nx], depth + 1);
                visited[ny][nx] = false;
            }
        }
    }
}

void getT(int y, int x){
    int cnt = 0;
    int sum = bd[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            sum += bd[ny][nx];
            cnt++;
        }
    }
    if(cnt == 3){
        tmp = max(tmp, sum);
    }
    else if(cnt == 4){
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                tmp = max(tmp, sum - bd[ny][nx]);
            }
        }
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}