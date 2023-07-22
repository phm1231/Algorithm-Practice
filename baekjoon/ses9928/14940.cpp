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

int n, m, sy, sx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > bd;
vector<vector<int> > dist;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(m, 0));
    dist.resize(n, vector<int>(m, 987654321));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
            if(bd[i][j] == 2){
                sy = i;
                sx = j;
            }
        }
    }
}

void solve()
{
    // 2는 목표지점
    // 1는 갈 수 있는 땅
    // 0은 갈 수 없는 땅
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    dist[sy][sx] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == 1 && dist[ny][nx] > dist[y][x] + 1){
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] == 0) cout << 0 << ' ';
            else if(dist[i][j] == 987654321) cout << -1 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}