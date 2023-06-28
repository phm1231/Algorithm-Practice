// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void bfs(int, int);

int n, m, k;
int answer = -1;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};
vector<vector<bool> > board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    board.resize(n+1, vector<bool>(m+1, false));
    visited.resize(n+1, vector<bool>(m+1, false));
    int r, c;
    for(int i=0; i<k; i++){
        cin >> r >> c;
        board[r][c] = true;
    }
}

void solve()
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] && !visited[i][j]){
                bfs(i, j);
            }
        }
    }
    cout << answer;
}

void bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    int siz = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(1<= ny && ny <= n && 1 <= nx && nx <= m){
                if(board[ny][nx] && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    siz++;
                }
            }
        }
    }
    answer = max(answer, siz);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}