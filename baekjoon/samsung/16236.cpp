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
void bfs(int sy, int sx);

int n;
int dy[] = {-1, 0, 1, 0}; // 위먼저, 왼쪽 먼저,
int dx[] = {0, -1, 0, 1};
int babyShark;
int answer = 0;
bool canEat;
pair<int, int> start;
vector<vector<int> > board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    babyShark = 2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                start.first=i;
                start.second=j;
                board[i][j] = 0;
            }
        }
    }
}

void solve()
{
    int cnt = 0;
    while(1){
        canEat = false;;
        bfs(start.first, start.second);
        if(!canEat) break;

        cnt++;
        if(cnt == babyShark){
            cnt = 0;
            babyShark++;
        }
    }
    cout << answer;
}

void bfs(int sy, int sx){
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    queue<pair<int, int> > q;
    priority_queue<pair<int, int> > pq; // y, x좌표가 작은 것부터 들어가야 함.
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    int dist = 0;

    while(!q.empty()){
        int qs = q.size();
        dist++;
        while(qs--){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0<=ny && ny < n && 0<=nx && nx < n){
                    // 지나감
                    if(board[ny][nx] == 0 || board[ny][nx] == babyShark){
                        if(visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                    // 먹음
                    else if(board[ny][nx] < babyShark){
                        pq.push(make_pair(-ny, -nx));
                        canEat = true;
                    }
                }
            }
        }
        if(canEat){
            int ny = -pq.top().first;
            int nx = -pq.top().second;
            board[ny][nx] = 0;
            answer += dist;
            start.first = ny;
            start.second = nx;
            return;
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}