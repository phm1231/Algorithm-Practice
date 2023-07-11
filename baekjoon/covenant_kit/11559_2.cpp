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
bool bfs(int, int);
void boom(int, int);
void down();

int n, m;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<string> board;
vector<string> empty_board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    n = 12;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
        empty_board.push_back(string(tmp.size(), '.'));
    }
    m = board[0].size();
}

void solve()
{
    int answer = 0;
    while(1){
        visited.clear();
        visited.resize(n, vector<bool>(m, false));
        queue<pair<int, int> > q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;
                if(!visited[i][j]){
                    if(bfs(i, j)) q.push(make_pair(i, j));
                }
            }
        }

        if(q.empty()){
            cout << answer;
            return;
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            boom(y, x);
        }
        down();
        answer++;
    }
}

void boom(int sy, int sx){
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    char target = board[sy][sx];

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        board[y][x] = '.';
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == target){
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}


bool bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
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
                if(!visited[ny][nx] && board[ny][nx] == board[sy][sx]){
                    visited[ny][nx] = true;
                    cnt++;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return cnt >= 4;
}

void down(){
    vector<string> newbd = empty_board;
    for(int j=0; j<m; j++){
        int ni = n-1;
        for(int ci=n-1; ci>=0; ci--){
            if(board[ci][j] != '.'){
                newbd[ni][j] = board[ci][j];
                ni--;
            }
        }
    }
    board = newbd;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}