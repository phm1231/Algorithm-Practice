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

int n, m, k, x1, y1, x2, y2;
int dy[] = {-1, 0, 0, 1}; // 위 아래
int dx[] = {0, -1, 1, 0}; // 좌 우

vector<string> board;

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
    }
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, y1--, x2--, y2--;
}

void solve()
{
    if(board[y1][x1] == '#' || board[y2][x2] == '#'){
        cout << -1;
        return;
    }

    vector<vector<bool> > visited(n, vector<bool>(m, false));
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {y1, x1}});

    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();

        if(visited[y][x]) continue;
        visited[y][x] = true;
        if(y == y2 && x == x2){
            cout << dist;
            return;
        }

        for(int i=0; i<4; i++){
            for(int w=1; w<=k; w++){
                int ny = y + dy[i] * w;
                int nx = x + dx[i] * w;

                // 올바른 방향의 범위임
                if(0 <= ny && ny < n && 0 <= nx && nx < m){
                    // 근데 벽있음
                    if(board[ny][nx] == '#') break;

                    if(!visited[ny][nx] && board[ny][nx] == '.'){
                        if(ny == y2 && nx == x2){
                            cout << dist + 1;
                            return;
                        }
                        pq.push({-(dist + 1), {ny, nx}});
                    }
                }
                else break;
            }
        }
    }


    cout << -1;
    return;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}