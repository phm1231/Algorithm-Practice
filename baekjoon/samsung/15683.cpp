// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int idx, vector<vector<bool> >& visited);
bool check(int, int);

int n, m;
int answer;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
vector<vector<int> > bd;
vector<pair<int, int> > cctvs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    answer = n*m;
    bd.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(bd[i][j] != 0 && bd[i][j] != 6){
                cctvs.push_back(make_pair(i, j));
            }
        }
    }
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    dfs(0, visited);
    cout << answer;
}

void dfs(int idx, vector<vector<bool> >& visited){
    if(idx == cctvs.size()){
        // answer 검사
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(bd[i][j] == 0  && !visited[i][j]) cnt++;
            }
        }
        answer = min(cnt, answer);
        return;
    }

    pair<int, int> cctv = cctvs[idx];
    int y = cctv.first;
    int x = cctv.second;

    // 1이면 1개,
    if(bd[y][x] == 1){
        for(int i=0; i<4; i++){
            vector<vector<bool> > v = visited;
            for(int j=1; ; j++){
                int ny = y + dy[i] * j;
                int nx = x + dx[i] * j;
                if(check(ny, nx)){
                    // 일반 공간 체크, 이어서 가능
                    if(bd[ny][nx] == 0) v[ny][nx] = true;
                    // 벽을 만나면 중지
                    else if(bd[ny][nx] == 6) break;
                    // 다른 것은 그냥 통과.
                }
                else break;
            }
            dfs(idx + 1, v);
        }
    }

    // 2이면 2개씩, (0, 2) +1
    else if(bd[y][x] == 2){ // 
        for(int i=0; i<2; i++){
            vector<vector<bool> > v = visited;
            int d1 = i;
            int d2 = i+2;
            bool wall1 = false;
            bool wall2 = false;
            for(int j=1; ;j++){
                int ny1 = y + dy[d1] * j;
                int nx1 = x + dx[d1] * j;
                if(check(ny1, nx1) && !wall1){
                    if(bd[ny1][nx1] == 0) v[ny1][nx1] = true;
                    else if(bd[ny1][nx1] == 6) wall1 = true;
                }
                int ny2 = y + dy[d2] * j;
                int nx2 = x + dx[d2] * j;
                if(check(ny2, nx2) && !wall2){
                    if(bd[ny2][nx2] == 0) v[ny2][nx2] = true;
                    else if(bd[ny2][nx2] == 6) wall2 = true;
                }
                if((!check(ny1, nx1) && !check(ny2, nx2)) || (wall1 && wall2)) break;
            }
            dfs(idx + 1, v);
        }
    }

    // 3이면 2개씩, (0, 1) +1
    else if(bd[y][x] == 3){
        for(int i=0; i<4; i++){
            vector<vector<bool> > v = visited;
            int d1 = i;
            int d2 = i+1 % 4;
            bool wall1, wall2;
            wall1 = wall2 = false;
            for(int j=1; ;j++){
                int ny1 = y + dy[d1] * j;
                int nx1 = x + dx[d1] * j;
                if(check(ny1, nx1) && !wall1){
                    if(bd[ny1][nx1] == 0) v[ny1][nx1] = true;
                    else if(bd[ny1][nx1] == 6) wall1 = true;
                }
                int ny2 = y + dy[d2] * j;
                int nx2 = x + dx[d2] * j;
                if(check(ny2, nx2) && !wall2){
                    if(bd[ny2][nx2] == 0) v[ny2][nx2] = true;
                    else if(bd[ny2][nx2] == 6) wall2 = true;
                }

                if((!check(ny1, nx1) && !check(ny2, nx2)) || (wall1 && wall2)) break;
            }
            dfs(idx + 1, v);
        }
    }
    // 4이면 3개씩, (0, 1, 2) + 1 % 4
    else if(bd[y][x] == 4){
        for(int i=0; i<4; i++){
            vector<vector<bool> > v = visited;
            int d1 = i;
            int d2 = i-1;
            if(d2 < 0) d2 = 3;
            int d3 = i+1;
            if(d3 >= 4) d3 = 0;
            bool wall1, wall2, wall3;
            wall1 = wall2 = wall3 = false;
            for(int j=1; ; j++){
                int ny1 = y + dy[d1] * j;
                int nx1 = x + dx[d1] * j;
                int ny2 = y + dy[d2] * j;
                int nx2 = x + dx[d2] * j;
                int ny3 = y + dy[d3] * j;
                int nx3 = x + dx[d3] * j;
                if(check(ny1, nx1) && !wall1){
                    if(bd[ny1][nx1] == 0) v[ny1][nx1] = true;
                    else if(bd[ny1][nx1] == 6) wall1 = true;
                }
                if(check(ny2, nx2) && !wall2){
                    if(bd[ny2][nx2] == 0) v[ny2][nx2] = true;
                    else if(bd[ny2][nx2] == 6) wall2 = true;
                }
                if(check(ny3, nx3) && !wall3){
                    if(bd[ny3][nx3] == 0) v[ny3][nx3] = true;
                    else if(bd[ny3][nx3] == 6) wall3 = true;
                }
                if((!check(ny1, nx1) && !check(ny2, nx2) && !check(ny3, nx3)) || (wall1 && wall2 && wall3)) break;
            }
            dfs(idx+1, v);
        }
    }
    // 5이면 모든 방향.
    else if(bd[y][x] == 5){
        vector<vector<bool> > v = visited;
        for(int i=0; i<4; i++){
            for(int j=1; ; j++){
                int ny = y + dy[i] * j;
                int nx = x + dx[i] * j;
                if(check(ny, nx)){
                    if(bd[ny][nx] == 0) v[ny][nx] = true;
                    else if(bd[ny][nx] == 6) break;
                }
                else break;
            }
        }
        dfs(idx+1, v);
    }
}

bool check(int y , int x){
    return (0 <= y && y < n && 0 <= x && x < m);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}