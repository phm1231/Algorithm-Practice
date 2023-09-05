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
void dist_dfs(int y, int x, int d, int cnt, int from);
void area_bfs(int sy, int sx);
void kruskal();
int getParent(int a);
void merge(int a, int b);

int n, m, area_cnt, answer, bridge_number;
vector<vector<int> > board;
vector<vector<int> > dist;
vector<vector<int> > area; // area[i][j] = board[i][j] 는 area섬에 속한다.
vector<int> parent;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    area.resize(n, vector<int>(m, -1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    // 섬을 나누면서 번호를 부여한다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 아직 구역이 정해져있지 않은 땅이면.
            if(board[i][j] == 1 && area[i][j] == -1){
                area_bfs(i, j);
            }
        }
    }

    dist.resize(area_cnt, vector<int>(area_cnt, MAX));
    parent.resize(area_cnt, 0);
    for(int i=0; i<area_cnt; i++) parent[i] = i;

    // 섬과 섬을 잇는 다리를 놓아 섬 간 최단거리를 구한다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 땅이면, 거리를 구한다.
            if(board[i][j] == 1){
                for(int d=0; d<4; d++){
                    dist_dfs(i, j, d, 0, area[i][j]);
                }
            }
        }
    }

    // 모든 섬을 연결하는 다리의 최솟값을 구한다.
    kruskal();
    if(bridge_number == area_cnt - 1) cout << answer;
    else cout << -1;
}

int getParent(int a){
    if(parent[a] == a) return a;
    else return parent[a] = getParent(parent[a]);
}

void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);

    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;    
}

void kruskal(){
    priority_queue<pair<int, pair<int, int> > > pq;
    for(int i=0; i<area_cnt; i++){
        for(int j=i+1; j<area_cnt; j++){
            if(dist[i][j] != MAX){
                pq.push(make_pair(-dist[i][j], make_pair(i, j)));
            }
        }
    }

    while(!pq.empty()){
        int cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = getParent(a);
        int pb = getParent(b);
        if(pa == pb) continue;

        merge(a, b);
        answer += cost;
        bridge_number++;

        if(bridge_number == area_cnt - 1) break;
    }
}

void dist_dfs(int y, int x, int d, int cnt, int from){
    int ny = y + dy[d];
    int nx = x + dx[d];

    if(0 <= ny && ny < n && 0 <= nx && nx < m){
        // 육지
        if(board[ny][nx] == 1){
            // 도착한 섬 번호
            int to = area[ny][nx];

            // 다리의 길이는 2이상이어야 한다.
            if(cnt < 2) return;
            // 동일한 섬이면 안된다.
            if(from == to) return;

            int minimumDist = min(dist[from][to], cnt);
            minimumDist = min(dist[to][from], cnt);

            dist[from][to] = dist[to][from] = minimumDist;

            return;
        }
        // 바다
        else if(board[ny][nx] == 0){
            // 계속 나아가며 다리를 놓는다.
            dist_dfs(ny, nx, d, cnt + 1, from);
        }
    }
}

void area_bfs(int sy, int sx){
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    area[sy][sx] = area_cnt;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == 0) continue;
                if(area[ny][nx] == -1){
                    area[ny][nx] = area_cnt;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    area_cnt++;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}