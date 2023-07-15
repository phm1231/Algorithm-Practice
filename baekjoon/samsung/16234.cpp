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
vector<pair<int, int> > makemyUnion(int sy, int sx);
void move(vector<pair<int, int> > myUnion);

int n, L, R;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> L >> R;
    board.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

// 인구 차이가 l명 이상 r명 이하.
void solve()
{
    int answer = 0;
    while(1){
        visited.clear();
        visited.resize(n, vector<bool>(n, false));
        bool isMove = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    vector<pair<int, int> > myUnion = makemyUnion(i, j);
                    if(myUnion.size() == 1) continue;
                    else{
                        isMove = true;
                        move(myUnion);
                    }
                }
            }
        }

        if(isMove) answer++;
        else break;
    }

    cout << answer;
}

void move(vector<pair<int, int> > myUnion){
    int sum = 0;
    for(pair<int, int> p: myUnion) sum += board[p.first][p.second];
    for(pair<int, int> p: myUnion) board[p.first][p.second] = sum / myUnion.size();
}

vector<pair<int, int> > makemyUnion(int sy, int sx){
    vector<pair<int, int> > ret;
    ret.push_back(make_pair(sy, sx));

    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=ny && ny<n && 0<=nx && nx<n){
                int gap = abs(board[y][x] - board[ny][nx]);
                if(L <=  gap && gap <= R){
                    if(!visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                        ret.push_back(make_pair(ny, nx));
                    }
                }
            }
        }
    }

    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}