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

int w, h; // 너비, 높이
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
long long W, B;

vector<string> board;
vector<vector<bool> > visited; 

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> w >> h;
    for(int i=0; i<h; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solve()
{
    visited.resize(h, vector<bool>(w, false));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }
    cout << W << ' ' << B;
}

void bfs(int sy, int sx){
    char team = board[sy][sx];
    long long cnt = 1;

    queue<pair<int, int> > q;
    q.push({sy, sx});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(board[ny][nx] == team && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }

    team == 'W' ? W += cnt*cnt : B += cnt*cnt;
}  



int main()
{
    init();
    input();
    solve();
    return 0;
}