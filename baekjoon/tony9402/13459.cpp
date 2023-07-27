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
pair<int, int> go(const pair<int, int> here, const pair<int, int> block, int dir);

int n, m;
vector<string> bd;
queue<pair<int, int> > RQ;
queue<pair<int, int> > BQ;
int ry, rx, by, bx, hy, hx;
int dy[] = {-1, 0, 1, 0}; // 상 좌 하 우
int dx[] = {0, -1, 0, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        bd.push_back(tmp);

        for(int j=0; j<m; j++){
            if(tmp[j] == 'R'){
                ry = i;
                rx = j;
                bd[ry][rx] = '.';
            }
            if(tmp[j] == 'B'){
                by = i;
                bx = j;
                bd[by][bx] = '.';
            }
            if(tmp[j] == 'O'){
                hy = i;
                hx = j;
            }
        }
    }
}

void solve()
{
    RQ.push(make_pair(ry, rx));
    BQ.push(make_pair(by, bx));
    bool visited[11][11][11][11] = {false, };
    visited[ry][rx][by][bx] = true;

    int cnt = 0;
    while(!RQ.empty()){
        int qs = RQ.size();
        cnt++;
        if(cnt > 11) break;

        while(qs--){
            pair<int, int> hereR = RQ.front();
            pair<int, int> hereB = BQ.front();
            RQ.pop(), BQ.pop();

            int cry = hereR.first;
            int crx = hereR.second;
            int cby = hereB.first;
            int cbx = hereB.second;

            // 파란 구슬이 들어감
            if(cby == hy && cbx == hx){
                continue;
            }
            // 빨간 구슬이 들어감.
            if(cry == hy && crx == hx){
                cout << 1;
                return;
            }

            for(int i=0; i<4; i++){
                // 위에 있는 것 먼저
                pair<int, int> nextR, nextB;
                if(i == 0){
                    if(cry <= cby){
                        nextR = go(hereR, hereB, i);
                        nextB = go(hereB, nextR, i);
                    }
                    else{
                        nextB = go(hereB, hereR, i);
                        nextR = go(hereR, nextB, i);
                    }
                }
                // 좌측에 있는 것 먼저
                else if(i == 1){
                    if(crx <= cbx){
                        nextR = go(hereR, hereB, i);
                        nextB = go(hereB, nextR, i);
                    }
                    else{
                        nextB = go(hereB, hereR, i);
                        nextR = go(hereR, nextB, i);
                    }
                }
                // 아래에 잇는 것 먼저
                else if(i == 2){
                    if(cry >= cby){
                        nextR = go(hereR, hereB, i);
                        nextB = go(hereB, nextR, i);
                    }
                    else{
                        nextB = go(hereB, hereR, i);
                        nextR = go(hereR, nextB, i);                    
                    }
                }
                // 우측에 있는 것 먼저
                else if(i == 3){
                    if(crx >= cbx){
                        nextR = go(hereR, hereB, i);
                        nextB = go(hereB, nextR, i);
                    }
                    else{
                        nextB = go(hereB, hereR, i);
                        nextR = go(hereR, nextB, i);
                    }
                }
                // 이동 끝.
                if(!visited[nextR.first][nextR.second][nextB.first][nextB.second]){
                    visited[nextR.first][nextR.second][nextB.first][nextB.second] = true;
                    RQ.push(nextR);
                    BQ.push(nextB);
                }
            }
        }
    }
    cout << 0;
    return;
}

pair<int, int> go(const pair<int, int> here, const pair<int, int> block, int dir){
    int y = here.first;
    int x = here.second;

    for(int i=1; ; i++){
        int by = y + dy[dir] * (i-1);
        int bx = x + dx[dir] * (i-1);
        int ny = y + dy[dir] * i;
        int nx = x + dx[dir] * i;
        // 범위를 만족하면
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(bd[ny][nx] == '#') return make_pair(by, bx);
            if(bd[ny][nx] == 'O') return make_pair(ny, nx);
            if(ny == block.first && nx == block.second) return make_pair(by, bx);
        }
        else 
            return make_pair(by, bx);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}