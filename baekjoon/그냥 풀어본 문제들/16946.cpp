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
void bfs(int sy, int sx);
int getAnswer(int y, int x);

int n, m, area;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<char> > board;
vector<vector<int> > answer;
vector<vector<bool> > visited;
vector<vector<int> > areas; // areas[i][j] = [i][j]가 몇 번 area에 속하는지.
vector<int> area_cnt; // area_cnt[i] = i번 구역의 개수

// 구역을 나눈다.
// 인접한 구역의 개수를 더한다.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    board.resize(n, vector<char>(m, '0'));
    answer.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    areas.resize(n, vector<int>(m, 0));

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
            if(!visited[i][j] && board[i][j] == '0'){
                areas[i][j] = area;
                bfs(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == '1'){
                answer[i][j] = getAnswer(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << answer[i][j];
        }
        cout << "\n";
    }
}

int getAnswer(int y, int x){
    
    // 다른 영역일 경우
    vector<bool> isUsed(area, false);
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(board[ny][nx] == '0'){
                int area_num = areas[ny][nx];
                if(isUsed[area_num]) continue;

                isUsed[area_num] = true;
                ret += area_cnt[area_num];
            }
        }
    }
    return ret % 10;
}

void bfs(int sy, int sx){
    int cnt = 1;
    queue<pair<int, int> > q;
    visited[sy][sx] = true;
    q.push(make_pair(sy, sx));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(visited[ny][nx]) continue;
                if(board[ny][nx] == '1') continue;

                areas[ny][nx] = area;
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                cnt++;
            }
        }
    }

    area_cnt.push_back(cnt % 10);
    area++;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}