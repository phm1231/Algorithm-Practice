// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool check(const int, const int);

int n, m, sy, sx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<string> board;
int visited[51][51][128];

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
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j] == '0'){
                sy = i;
                sx = j;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<128; k++){
                visited[i][j][k] = 987654321;
            }
        }
    }
}

void solve()
{
    queue<pair<unsigned char, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(sy, sx)));
    visited[sy][sx][0] = 0;

    while(!q.empty()){
        int y = q.front().second.first;
        int x = q.front().second.second;
        unsigned char key = q.front().first;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
    
            if(check(ny, nx)){
                // 열쇠
                if('a' <= board[ny][nx] && board[ny][nx] <= 'z'){
                    unsigned char a = 1;
                    a = a << (board[ny][nx] - 'a' + 1); // 습득한 키
                    unsigned char nextkey = key | a;

                    if(visited[ny][nx][nextkey] > visited[y][x][key] + 1){
                        visited[ny][nx][nextkey] = visited[y][x][key] + 1;
                        q.push(make_pair(nextkey, make_pair(ny, nx)));
                    }
                }
                // 문
                else if('A' <= board[ny][nx] && board[ny][nx] <= 'Z'){
                    unsigned char a = 1;
                    a = a << (board[ny][nx] - 'A' + 1);
                    // 열쇠가 있으면
                    if(key & a){
                        if(visited[ny][nx][key] > visited[y][x][key] + 1){
                            visited[ny][nx][key] = visited[y][x][key] + 1;
                            q.push(make_pair(key, make_pair(ny, nx)));
                        }
                    }
                }
                // 출구
                else if(board[ny][nx] == '1'){
                    cout << visited[y][x][key] + 1;
                    return;
                }
                // 벽
                else if(board[ny][nx] == '#') continue;
                // 빈칸이나 0
                else if(board[ny][nx] == '.' || board[ny][nx] == '0'){
                    if(visited[ny][nx][key] > visited[y][x][key] + 1){
                        visited[ny][nx][key] = visited[y][x][key] + 1;
                        q.push(make_pair(key, make_pair(ny, nx)));
                    }
                }
            }
        }
    }
    cout << -1;
}

bool check(const int ny, const int nx){
    return (0<=ny && ny<n && 0<=nx && nx<m);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}