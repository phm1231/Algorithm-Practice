// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 987654321

void init();
void input();
void solve();"
"

int n, m, k, x1, y1, x2, y2;
int dy[] = {-1, 0, 0, 1}; // 위 아래
int dx[] = {0, -1, 1, 0}; // 좌 우

vector<string> board;
int visited[1002][1002];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
        
        for(int j=0; j<m; j++){
            visited[i][j] = MAX;
        }
    }
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, y1--, x2--, y2--;
}

void solve()
{
    queue<pair<int, int> > q;

    q.push({y1, x1});
    visited[y1][x1] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            for(int w=1; w<=k; w++){
                int ny = y + (dy[i] * w);
                int nx = x + (dx[i] * w);
                // 올바른 방향의 범위임
                if(0 <= ny && ny < n && 0 <= nx && nx < m){
                    // 벽이면
                    if(board[ny][nx] == '#') break;

                    // 처음 방문한 지점이면
                    if(visited[ny][nx] == MAX){
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push({ny, nx});
                    }
                    // 방문한 적이 있음
                    else{
                        // 이미 더 저렴한 값으로 방문한 적이 있으면
                        if(visited[ny][nx] < visited[y][x] + 1) break;
                        // 동일한 가격이면 굳이 더 멀리 달리지 않아보아도 된다. 해당 지점에서 다시 달리는 것과 동일하므로.
                        else if(visited[ny][nx] == visited[y][x] + 1) continue;
                        // 더 비싼 비용이 필요하면
                        else break;
                    }
                }
            }
        }
    }

    if(visited[y2][x2] == MAX) cout << -1;
    else cout << visited[y2][x2];
    return;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}