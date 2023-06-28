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

int n, m;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, 1, -1, 0, 1, -1};

vector<vector<int> > board;
vector<vector<int> > visited;
vector<pair<int, int> > sharks;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<int>(m, 987654321));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) sharks.push_back({i, j});
        }
    }
}

void solve()
{
    for(pair<int, int>& shark: sharks){
        bfs(shark.first, shark.second);
    }
    int answer = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer = max(answer, visited[i][j]);
        }
    }
    cout << answer;
}

void bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push({sy, sx});
    visited[sy][sx] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == 0 && visited[ny][nx] > visited[y][x] + 1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
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