// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct node{
    int y, x, cnt, w;
    node(int y, int x, int cnt, int w): y(y), x(x), cnt(cnt), w(w) {}
}node;

void init();
void input();
void solve();

int dy[] = {0, -1, 0, 1, 0};
int dx[] = {0, 0, -1, 0, 1};
int n, m, k;
vector<vector<char> > bd;
int visited[1001][1001][11][2];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    bd.resize(n, vector<char>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            for(int k=0; k<11; k++){
                visited[i][j][k][0] = visited[i][j][k][1] = 987654321;
            }
        }
    }
}

void solve()
{
    queue<node> q;
    q.push(node(0, 0, 0, 0)); // 낮이면 0, 밤이면 1
    visited[0][0][0][0] = 1;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        int w = q.front().w;
        q.pop();

        for(int i=0; i<5; i++){
            // 지금이 낮이라면 제자리에서 기다릴 필요가 없다
            // if(i == 0 && w == 0) continue;

            int ny = y + dy[i];
            int nx = x + dx[i];
            int next_w = (w == 0 ? 1 : 0);

            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == '0'){
                    if(visited[ny][nx][cnt][next_w] > visited[y][x][cnt][w] + 1){
                        visited[ny][nx][cnt][next_w] = visited[y][x][cnt][w] + 1;
                        q.push(node(ny, nx, cnt, next_w));
                    }
                }
                else if(bd[ny][nx] == '1'){
                    // 벽이지만 제자리에서 있는 경우
                    if(i == 0){
                        if(visited[ny][nx][cnt][next_w] > visited[y][x][cnt][w] + 1){
                            visited[ny][nx][cnt][next_w] = visited[y][x][cnt][w] + 1;
                            q.push(node(ny, nx, cnt, next_w));
                        }
                    }
                    // k번 넘게 벽을 부수지 않고, 지금이 낮이라면
                    else if(cnt + 1 <= k && w == 0){
                        if(visited[ny][nx][cnt+1][next_w] > visited[y][x][cnt][w] + 1){
                            visited[ny][nx][cnt+1][next_w] = visited[y][x][cnt][w] + 1;
                            q.push(node(ny, nx, cnt+1, next_w));
                        }
                    }
                }
            }
        }
    }

    int answer = 987654321;

    for(int i=0; i<=k; i++){
        answer = min(visited[n-1][m-1][i][0], answer);
        answer = min(visited[n-1][m-1][i][1], answer);
    }

    if(answer == 987654321) cout << -1;
    else cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}