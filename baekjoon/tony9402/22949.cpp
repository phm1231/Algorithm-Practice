// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct node{
    int y, x, dir, cnt;
    node(int y, int x, int dir, int cnt): y(y), x(x), dir(dir), cnt(cnt) {}
}node;

void init();
void input();
void solve();
pair<int, int> spin(const pair<int, int>& p);

bool visited[501][501][4] = {false, };
int n, k;
queue<node> q;
vector<vector<vector<char> > > bd;
int dy[] = {0, -1, 0, 1, 0};
int dx[] = {0, 0, -1, 0, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> k;
    n = 4*k;
    bd.resize(n, vector<vector<char> >(n, vector<char>(4, ' ')));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j][0];
            if(bd[i][j][0] == 'S'){
                q.push(node(i, j, 0, 0));
                bd[i][j][0] = '.';
                visited[i][j][0] = true;
            }

            pair<int, int> before = make_pair(i, j);
            for(int d=1; d<4; d++){
                pair<int, int> after = spin(before);
                bd[after.first][after.second][d] = bd[before.first][before.second][d-1];
                before = after;
            }

        }
    }
}

void solve()
{
    // BFS
    while(!q.empty()){
        node here = q.front();
        q.pop();

        int y = here.y;
        int x = here.x;
        int dir = here.dir;
        int cnt = here.cnt;

        if(bd[y][x][dir] == 'E'){
            cout << cnt;
            return;
        }

        for(int i=0; i<5; i++){
            // 이동하거나 가만히 있는다.
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 내라면
            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                // 갈 수 있는 곳이라면
                // 같은 구역이라면 (dir+1)%4, 아니라면 1
                int nextdir = (y/4 == ny/4 && x/4 == nx/4) ? (dir+1)%4 : 1;
                pair<int, int> nextLocation = spin(make_pair(ny, nx)); // 시계방향으로 90도 회전한다.
                ny = nextLocation.first;
                nx = nextLocation.second;
                if(!visited[ny][nx][nextdir] && bd[ny][nx][nextdir] != '#' ){ 
                    visited[ny][nx][nextdir] = true;
                    q.push(node(ny, nx, nextdir, cnt + 1));
                }
            }
        }
    }
    cout << -1;
    return;
}


pair<int, int> spin(const pair<int, int>& p){
    int y = p.first;
    int x = p.second;

    int baseY = (y/4) * 4;
    int baseX = (x/4) * 4;
    y %= 4;
    x %= 4;
    return make_pair(baseY+x, baseX+4-y-1);
}



int main()
{
    init();
    input();
    solve();
    return 0;
}