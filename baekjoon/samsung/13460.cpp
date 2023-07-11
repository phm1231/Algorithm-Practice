// based problem:
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define MAX 100001

typedef struct location{
    int ry, rx, by, bx;
    location(int ry, int rx, int by, int bx): ry(ry), rx(rx), by(by), bx(bx) {}
}location;


void init();
void input();
void solve();
location move(location here, int dir, bool redFirst);

int n, m;
vector<string> board;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solve()
{
    location l(0, 0, 0, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'R'){
                board[i][j] = '.';
                l.ry = i;
                l.rx = j;
            }
            else if(board[i][j] == 'B'){
                board[i][j] = '.';
                l.by = i;
                l.bx = j;
            }
        }
    }

    int cnt = 0;
    queue<location> q;
    q.push(l);
    bool visited[11][11][11][11] = {false, };
    visited[l.ry][l.rx][l.by][l.bx] = true;

    while(!q.empty()){
        int qs = q.size();
        cnt++;
        if(cnt == 11){
            cout << -1;
            return;
        }
        while(qs--){
            location here = q.front();
            q.pop();

            // 상 하 좌 우 
            for(int i=0; i<4; i++){
                // 기울이는 방향에 있는 것을 먼저 처리해야 함. 즉, 한 구슬은 다른 구슬에 영향을 줄 수 없음.
                bool redFirst = false;
                // 상, red가 blue보다 위에 있을 경우 
                if(i == 0 && here.ry < here.by) redFirst = true;
                // 하, red가 blue보다 아래에 있을 경우
                else if(i == 1 && here.ry > here.by) redFirst = true;
                // 좌, red가 blue보다 좌측에 있을 경우
                else if(i == 2 && here.rx < here.bx) redFirst = true;
                // 우, red가 blue보다 우측에 있을 경우
                else if(i == 3 && here.rx > here.bx) redFirst = true;

                location next = move(here, i, redFirst);
                // 홀 검사
                // 둘 다 빠짐
                if(board[next.ry][next.rx] == 'O' && board[next.by][next.bx] == 'O') continue;
                // 레드만 빠짐
                else if(board[next.ry][next.rx] == 'O' && board[next.by][next.bx] != 'O'){
                    cout << cnt;
                    return;
                }
                // 블루만 빠짐
                else if(board[next.ry][next.rx] != 'O' && board[next.by][next.bx] == 'O'){
                    continue;
                }
                // 둘 다 빠지지 않음
                else if(board[next.ry][next.rx] != 'O' && board[next.by][next.bx] != 'O'){
                    if(!visited[next.ry][next.rx][next.by][next.bx]){
                        visited[next.ry][next.rx][next.by][next.bx] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    cout << -1;
}

location move(location here, int dir, bool redFirst){
    // sy sx는 red 혹은 blue 좌표.
    int ry = here.ry;
    int rx = here.rx;
    int by = here.by;
    int bx = here.bx;

    if(redFirst){
        // 빨강
        for(int w=1; ; w++){
            int ny = ry + (dy[dir]*w);
            int nx = rx + (dx[dir]*w);
            // 지나간다.
            if(board[ny][nx] == '.') continue;
            // 홀을 만나면 빠질 수 있다.
            else if(board[ny][nx] == 'O'){
                ry = ny;
                rx = nx;
                break;
            }
            // 벽을 만났다면, 이전 좌표에서 정지한다.
            else if(board[ny][nx] == '#'){
                ry = ry + (dy[dir]*(w-1));
                rx = rx + (dx[dir]*(w-1));
                break;
            }
        }
        // 파랑
        for(int w=1; ; w++){
            int ny = by + (dy[dir]*w);
            int nx = bx + (dx[dir]*w);
            // 지나간다.
            if(board[ny][nx] == '.'){
                // 알고보니 빨간 구슬임
                if(ny == ry && nx == rx){
                    by = by + (dy[dir]*(w-1));
                    bx = bx + (dx[dir]*(w-1));
                    break;
                }
                else continue;
            }
            // 홀을 만나면 빠질 수 있다.
            else if(board[ny][nx] == 'O'){
                by = ny;
                bx = nx;
                break;
            }
            // 벽을 만났다면, 이전 좌표에서 정지한다.
            else if(board[ny][nx] == '#'){
                by = by + (dy[dir]*(w-1));
                bx = bx + (dx[dir]*(w-1));
                break;
            }
        }
    }
    else{
        // 파랑
        for(int w=1; ; w++){
            int ny = by + (dy[dir]*w);
            int nx = bx + (dx[dir]*w);
            // 지나간다.
            if(board[ny][nx] == '.') continue;
            // 홀을 만나면 빠질 수 있다.
            else if(board[ny][nx] == 'O'){
                by = ny;
                bx = nx;
                break;
            }
            // 벽을 만났다면, 이전 좌표에서 정지한다.
            else if(board[ny][nx] == '#'){
                by = by + (dy[dir]*(w-1));
                bx = bx + (dx[dir]*(w-1));
                break;
            }
        }
        // 빨강
        for(int w=1; ; w++){
            int ny = ry + (dy[dir]*w);
            int nx = rx + (dx[dir]*w);
            // 지나간다.
            if(board[ny][nx] == '.'){
                // 알고보니 파란구슬임
                if(ny == by && nx == bx){
                    ry = ry + (dy[dir]*(w-1));
                    rx = rx + (dx[dir]*(w-1));
                    break;
                }
                else continue;
            }
            // 홀을 만나면 빠질 수 있다.
            else if(board[ny][nx] == 'O'){
                ry = ny;
                rx = nx;
                break;
            }
            // 벽을 만났다면, 이전 좌표에서 정지한다.
            else if(board[ny][nx] == '#'){
                ry = ry + (dy[dir]*(w-1));
                rx = rx + (dx[dir]*(w-1));
                break;
            }
        }
    }

    return location(ry, rx, by, bx);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}