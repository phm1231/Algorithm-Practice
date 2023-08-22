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
void bfs(int hy, int hx);

int n, sy, sx, baby, answer;
bool eat;
vector<vector<int> > bd;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    baby = 2;
    bd.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
            if(bd[i][j] == 9){
                sy = i;
                sx = j;
                bd[i][j] = 0;
            }
        }
    }
}

void solve()
{
    int cnt = 0;
    while(1){
        eat = false;
        bfs(sy, sx);

        if(!eat){
            cout << answer;
            return;
        }
        else{
            cnt++;
            if(cnt == baby){
                cnt = 0;
                baby++;
            }
        }
    }
}

void bfs(int hy, int hx){

    queue<pair<int, int> > q;
    q.push(make_pair(hy, hx));
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    visited[hy][hx] = true;
    int dist = 0;

    // 가장 y좌표가 작고 x좌표가 작은 것
    priority_queue<pair<int, int> > pq;

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
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(visited[ny][nx]) continue;

                    // 지나감
                    if(bd[ny][nx] == 0 || bd[ny][nx] == baby){
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                    // 먹음
                    else if(bd[ny][nx] < baby){
                        visited[ny][nx] = true;
                        pq.push(make_pair(-ny, -nx));
                    }
                }
            }
        }

        if(!pq.empty()){
            sy = -pq.top().first;
            sx = -pq.top().second;
            bd[sy][sx] = 0;
            eat = true;
            answer += dist;
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