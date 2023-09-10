#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
pair<int, int> go(pair<int, int> start);
pair<int, int> getNextLocation(pair<int, int> start);

int n, m, sy, sx;
int cnt;
ll fuel;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > board;
vector<pair<int, int> > src;
vector<pair<int, int> > dst;
vector<bool> isEnd(401, false);

// 현재 위치에서 최단거리가 가장 짧은 승객을 고르는데, 그 중 행번호, 열번호가 가장 작은 승객을 고른다.
// 같은 위치면 거리는 0, 칸당 연료는 1
// 승객을 이동시키면 소모한 두 배가 충전된다.
// 바닥나면 퇴근
// 이동시킨 동시에 바닥나면 충전

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> fuel;
    board.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    cin >> sy >> sx;
    sy--;
    sx--;

    for(int i=0; i<m; i++){
        int fromY, fromX, toY, toX;
        cin >> fromY >> fromX >> toY >> toX;
        src.push_back(make_pair(fromY - 1, fromX - 1));
        dst.push_back(make_pair(toY - 1, toX - 1));
    }
}

void solve()
{
    // 다음 승객을 찾아서 이동한다.
    pair<int, int> here, next;
    here = make_pair(sy, sx);

    while(1){
        if(cnt == m){
            cout << fuel;
            return;
        }
        pair<int, int> next = getNextLocation(here);
        // 다음 승객에게 가다가 연료가 바닥났다.
        if(fuel <= 0){
            cout << -1;
            return;
        }
        // 다음 승객을 태우러 갈 수 없다.
        if(next.first == -1 && next.second == -1){
            cout << -1;
            return;
        }
        // 다음 승객을 목적지로 이동시킨다.
        here = go(next);
        // 도착할 수 없다.
        if(here.first == -1 && here.second == -1){
            cout << -1;
            return;
        }
        cnt++;
    }

}

pair<int, int> go(pair<int, int> start){
    vector<vector<int> > bd = board;
    int targetIdx;

    for(int i=0; i<m; i++){
        if(src[i].first == start.first && src[i].second == start.second){
            targetIdx = i;
            bd[dst[i].first][dst[i].second] = 2;
            break;
        }
    }

    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    q.push(start);
    visited[start.first][start.second] = true;
    int dist = 0;
    bool canArrive = false;

    while(!q.empty()){
        int qs = q.size();

        while(qs--){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(bd[y][x] == 2){
                canArrive = true;
                break;
            }

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(!visited[ny][nx] && bd[ny][nx] != 1){
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }

        if(canArrive) break;
        dist++;
    }
    
    // 목적지에 도착함.
    if(canArrive){
        fuel -= dist;
        if(fuel >= 0){
            isEnd[targetIdx] = true;
            fuel += dist * 2;
            return dst[targetIdx];
        }
        else{
            return make_pair(-1, -1);
        }
    }
    // 목적지에 도착할 수 없음.
    else{
        return make_pair(-1, -1);
    }
}

pair<int, int> getNextLocation(pair<int, int> start){
    vector<vector<int> > bd = board;

    for(int i=0; i<m; i++){
        if(isEnd[i]) continue;
        int y = src[i].first;
        int x = src[i].second;
        bd[y][x] = 2;
    }

    queue<pair<int, int > > q;
    priority_queue<pair<int, int> > pq;

    q.push(start);
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    visited[start.first][start.second] = true;
    int dist = 0; // 태우러 가는데 소모하는 연로.

    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(bd[y][x] == 2) pq.push(make_pair(-y, -x));

            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(!visited[ny][nx] && bd[ny][nx] != 1){
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        if(!pq.empty()) break;
        dist++;
    }

    // 다음 승객에게 갈 수가 없음.
    if(pq.empty()){
        return make_pair(-1, -1);
    }

    else{
        fuel -= dist;
        return make_pair(pq.top().first * -1, pq.top().second * -1);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}