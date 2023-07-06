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
void dfs(int, int, vector<vector<int> >&);
vector<vector<int> > move(int dir, vector<vector<int> > bd);

int n, answer;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<vector<int> > board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}
//  이동하려고 하는 쪽의 칸이 먼저 합쳐진다. 
void solve()
{
    for(int i=0; i<4; i++){
        dfs(i, 0, board);
    }
    cout << answer;
}

// 현재 cnt번 이동함
void dfs(int dir, int cnt, vector<vector<int> >& bd){
    if(cnt == 5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                answer = max(answer, bd[i][j]);
            }
        }
        return;
    }

    // dir 방향으로 이동하여 보드 만듬
    vector<vector<int> > newbd = move(dir, bd);
    // dfs
    for(int i=0; i<4; i++){
        dfs(i, cnt + 1, newbd);
    }
}

vector<vector<int> > move(int dir, vector<vector<int> > bd){
    vector<vector<int> > newbd(n, vector<int>(n, 0));
    vector<vector<int> > retbd(n, vector<int>(n, 0));

    // 위로
    if(dir == 0){
        // 위로 땡기면서 0을 제거한다.
        for(int x=0; x<n; x++){
            int cy, ny;
            for(cy = ny = 0; cy<n; cy++){
                if(bd[cy][x] == 0) continue;
                newbd[ny][x] = bd[cy][x];
                ny++;
            }            
        }
        // 합친다
        for(int x=0; x<n; x++){
            for(int y=0; y<n-1; y++){
                if(newbd[y][x] == 0) continue;
                if(newbd[y][x] == newbd[y+1][x]){
                    newbd[y][x] += newbd[y+1][x];
                    newbd[y+1][x] = 0;
                }
            }
        }
        // 또 위로 땡기면서 0을 제거한다.
        for(int x=0; x<n; x++){
            int cy, ny;
            for(cy = ny = 0; cy<n; cy++){
                if(newbd[cy][x] == 0) continue;
                retbd[ny][x] = newbd[cy][x];
                ny++;
            }            
        }
    }
    // 우측으로
    else if(dir == 1){
        // 우로 밀면서 0을 제거한다.
        for(int y=0; y<n; y++){
            int cx, nx;
            for(cx = nx = n-1; cx>=0; cx--){
                if(bd[y][cx] == 0) continue;
                newbd[y][nx] = bd[y][cx];
                nx--;
            }            
        }
        // 합친다
        for(int y=0; y<n; y++){
            for(int x=n-1; x>=1; x--){
                if(newbd[y][x] == 0) continue;
                if(newbd[y][x] == newbd[y][x-1]){
                    newbd[y][x] += newbd[y][x-1];
                    newbd[y][x-1] = 0;
                }
            }
        }
        // 또 우로 땡기면서 0을 제거한다.
        for(int y=0; y<n; y++){
            int cx, nx;
            for(cx = nx = n-1; cx>=0; cx--){
                if(newbd[y][cx] == 0) continue;
                retbd[y][nx] = newbd[y][cx];
                nx--;
            }            
        }
    }
    // 아래로
    else if(dir == 2){
        // 아래로 밀면서 0을 제거한다.
        for(int x=0; x<n; x++){
            int cy, ny;
            for(cy = ny = n-1; cy>=0; cy--){
                if(bd[cy][x] == 0) continue;
                newbd[ny][x] = bd[cy][x];
                ny--;
            }            
        }
        // 합친다
        for(int x=0; x<n; x++){
            for(int y=n-1; y>=1; y--){
                if(newbd[y][x] == 0) continue;
                if(newbd[y][x] == newbd[y-1][x]){
                    newbd[y][x] += newbd[y-1][x];
                    newbd[y-1][x] = 0;
                }
            }
        }
        // 또 아래로 땡기면서 0을 제거한다.
        for(int x=0; x<n; x++){
            int cy, ny;
            for(cy = ny = n-1; cy>=0; cy--){
                if(newbd[cy][x] == 0) continue;
                retbd[ny][x] = newbd[cy][x];
                ny--;
            }            
        }
    }
    // 좌측으로
    else if(dir == 3){
        //좌로 땡기면서 0을 제거한다.
        for(int y=0; y<n; y++){
            int cx, nx;
            for(cx = nx = 0; cx<n; cx++){
                if(bd[y][cx] == 0) continue;
                newbd[y][nx] = bd[y][cx];
                nx++;
            }            
        }
        // 합친다
        for(int y=0; y<n; y++){
            for(int x=0; x<n-1; x++){
                if(newbd[y][x] == 0) continue;
                if(newbd[y][x] == newbd[y][x+1]){
                    newbd[y][x] += newbd[y][x+1];
                    newbd[y][x+1] = 0;
                }
            }
        }
        // 또 좌로 땡기면서 0을 제거한다.
        for(int y=0; y<n; y++){
            int cx, nx;
            for(cx = nx = 0; cx<n; cx++){
                if(newbd[y][cx] == 0) continue;
                retbd[y][nx] = newbd[y][cx];
                nx++;
            }            
        }
    }
    return retbd;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}