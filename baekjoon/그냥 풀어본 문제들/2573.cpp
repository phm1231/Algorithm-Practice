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
bool isAllmelt(const vector<vector<int> >& origin);
vector<vector<int> > melt(const vector<vector<int> >& origin);
int getCnt(const vector<vector<int> >& origin);

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    bd.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    int day = 0;
    while(1){
        if(isAllmelt(bd)){
            cout << 0;
            return;
        }
        int cnt = getCnt(bd);
        if(cnt > 1){
            cout << day;
            return;
        }
        bd = melt(bd);
        day++;
    }
}

int getCnt(const vector<vector<int> >& origin){
    vector<vector<int> > visited(n, vector<int>(m, 0));
    int cnt = 1;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(origin[y][x] > 0 && visited[y][x] == 0){
                visited[y][x] = cnt;
                queue<pair<int, int> > q;
                q.push(make_pair(y, x));

                while(!q.empty()){
                    int hy = q.front().first;
                    int hx = q.front().second;
                    q.pop();
                    for(int i=0; i<4; i++){
                        int ny = hy + dy[i];
                        int nx = hx + dx[i];
                        if(0 <= ny && ny < n && 0 <= nx && nx < m && origin[ny][nx] > 0 && visited[ny][nx] == 0){
                            visited[ny][nx] = cnt;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }

                cnt++;
            }
        }
    }
    return cnt - 1;
}

bool isAllmelt(const vector<vector<int> >& origin){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(origin[i][j] > 0) return false;
        }
    }
    return true;
}

vector<vector<int> > melt(const vector<vector<int> >& origin){
    vector<vector<int> > ret = origin;

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(origin[y][x] > 0){
                int cnt = 0;
                for(int i=0; i<4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(0 <= ny && ny < n && 0 <= nx && nx < m){
                        if(origin[ny][nx] == 0) cnt++;
                    }
                }                
                ret[y][x] -= cnt;
                if(ret[y][x] < 0) ret[y][x] = 0;
            }
        }
    }

    return ret;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}