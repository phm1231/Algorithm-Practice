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

const int n = 12;
const int m = 6;
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, 1, -1, 0};
int answer = 0;
bool isBoom;
vector<string> board;
vector<pair<int, int> > booms;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solve()
{
    while(1){
        isBoom = false;
        visited.clear();
        visited.resize(n, vector<bool>(m, false));
        booms.clear();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] != '.' && !visited[i][j]){
                    bfs(i, j);
                }
            }
        }
        // 터뜨리기
        if(isBoom){
            for(pair<int, int>& boom: booms){
                int y = boom.first;
                int x = boom.second;
                board[y][x] = '.';
            }
            answer++;
            // 떨어뜨리기
            for(int i=n-1; i>=0; i--){ // y축
                for(int x=0; x<m; x++){ // x축
                    if(board[i][x] == '.'){ // 가장 아래가 .이라면
                        // 위에서 찾는다.
                        for(int y=i-1; y>=0; y--){
                            if(board[y][x] != '.'){
                                board[i][x] = board[y][x];
                                board[y][x] = '.';
                                break;
                            }
                        }
                    }
                }
            }
        }
        else break;
    }
    cout << answer;
}

void bfs(int sy, int sx){
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    v.push_back(make_pair(sy, sx));
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;

    int cnt = 1;
    char target = board[sy][sx];

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(!visited[ny][nx] && board[ny][nx] == target){
                    visited[ny][nx] = true;
                    v.push_back(make_pair(ny, nx));
                    cnt++;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    // 4개 미만이면 나가기.
    if(cnt < 4) return;

    // 터뜨릴 것 저장
    isBoom = true;
    for(int i=0; i<v.size(); i++){
        booms.push_back(v[i]);
    }

}

int main()
{
    init();
    input();
    solve();
    return 0;
}
