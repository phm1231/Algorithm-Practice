// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct node{
    int y, x, cnt;
    node(int y, int x, int c): y(y), x(x), cnt(c) {}
}node;

void init();
void input();
void solve();

int n, m, k;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<char> > bd;
vector<vector<vector<int> > > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    bd.resize(n, vector<char>(m, 0));
    visited.resize(n, vector<vector<int> >(m, vector<int>(11, -1)));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    queue<node> q;
    q.push(node(0, 0, 0));
    visited[0][0][0] = 1;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y == n-1 && x == m-1){
            cout << visited[y][x][cnt];
            return;
        }
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                // 이동할 수 있는 곳
                if(bd[ny][nx] == '0'){
                    if(visited[ny][nx][cnt] == -1 || visited[ny][nx][cnt] > visited[y][x][cnt] + 1){
                        visited[ny][nx][cnt] = visited[y][x][cnt] + 1;
                        q.push(node(ny, nx, cnt));
                    }
                }
                else if(bd[ny][nx] == '1'){
                    if(cnt + 1 <= k){
                        if(visited[ny][nx][cnt + 1] == -1 || visited[ny][nx][cnt + 1] > visited[y][x][cnt] + 1){
                            visited[ny][nx][cnt + 1] = visited[y][x][cnt] + 1;
                            q.push(node(ny, nx, cnt + 1));
                        }
                    }
                }                
            }
        }
    }
    cout << -1;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}