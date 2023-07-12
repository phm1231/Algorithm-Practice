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
void bfs(int ,int, int);

int n, m, answer;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
vector<vector<int> > board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    for(int i=0; i<n*m; i++){
        for(int j=i+1; j<n*m; j++){
            for(int k=j+1; k<n*m; k++){
                bfs(i, j, k);
            }
        }
    }
    cout << answer;
}

void bfs(int a, int b, int c){
    int ay = a / m;
    int ax = a % m;
    int by = b / m;
    int bx = b % m;
    int cy = c / m;
    int cx = c % m;
    // 각 좌표는 1로 만들 좌표들.
    if( board[ay][ax] != 0 || board[by][bx] != 0 || board[cy][cx] != 0) return;


    vector<vector<int> > bd = board;
    bd[ay][ax] = bd[by][bx] = bd[cy][cx] = 1;
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] == 2){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    while(!q.empty()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        for(int i=0; i<4; i++){
                            int ny = y + dy[i];
                            int nx = x + dx[i];
                            if(0<=ny&&ny<n&&0<=nx&&nx<m){
                                if(bd[ny][nx] == 0 && !visited[ny][nx]){
                                    visited[ny][nx] = true;
                                    bd[ny][nx] = 2;
                                    q.push(make_pair(ny, nx));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] == 0) cnt++;
        }
    }
    answer = max(answer, cnt);
       
}

int main()
{
    init();
    input();
    solve();
    return 0;
}