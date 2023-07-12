// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int hy, int hx, int sum, int depth);
void shape1(int y, int x); // ㅗ
void shape2(int y, int x); // ㅏ
void shape3(int y, int x); // ㅜ
void shape4(int y, int x); // ㅓ

int n, m;
int answer = 0;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};
vector<vector<int> > board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            dfs(i, j, board[i][j], 1);
            visited[i][j] = false;
            // ㅗ자 모양 블록 처리
            shape1(i, j);
            shape2(i, j);
            shape3(i, j);
            shape4(i, j);
        }
    }
    cout << answer;
}


void dfs(int y, int x, int sum, int depth){ 
    visited[y][x] = true;
    if(depth == 4){
        answer = max(sum, answer);
        return;
    }
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0<=ny && ny < n && 0<=nx && nx<m){
            if(!visited[ny][nx]){
                visited[ny][nx] = true;
                dfs(ny, nx, sum + board[ny][nx], depth + 1);
                visited[ny][nx] = false;
            }
        }
    }
}

void shape1(int y, int x){ // ㅗ
    if(y-1 >= 0 && x+2 < m){
        answer = max(answer, board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+1]);
    }
}
void shape2(int y, int x){ // ㅏ
    if(y+2 < n && x+1 < m){
        answer = max(answer, board[y][x] + board[y+1][x] + board[y+2][x] + board[y+1][x+1]);
    }
}
void shape3(int y, int x){ // ㅜ
    if(y+1 < n && x+2 < m){
        answer = max(answer, board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+1]);
    }
}
void shape4(int y, int x){ // ㅓ
    if(y-1 >= 0 && y+1 < n && x+1 < m){
        answer = max(answer, board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y+1][x+1]);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}