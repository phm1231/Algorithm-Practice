#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
int Bfs(int sy, int sx);

const int MAX = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int n, m;
vector<vector<int> > bd;
vector<vector<bool> > visited;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void Solve()
{
    int max_area = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] == 1 && !visited[i][j]){
                max_area = max(max_area, Bfs(i, j));
                cnt++;
            }    
        }
    }
    cout << cnt << "\n" << max_area;
}

int Bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    int cnt = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == 0) continue;
                if(visited[ny][nx]) continue;
                cnt++;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    return cnt;
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}