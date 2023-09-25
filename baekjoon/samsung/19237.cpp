#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define endl "\n";

using namespace std;

typedef struct Shark{
    int y, x, dir;
    // 위, 아래, 좌, 우를 향할 때 우선 순위
    vector<vector<int> > dirs;
    Shark(int y, int x, int dir, const vector<vector<int> >& dirs): y(y), x(x), dir(dir), dirs(dirs) {}
}Shark;

typedef struct Smoke{
    int y, x, idx, day;
    Smoke(int y, int x, int idx, int day): y(y), x(x), idx(idx), day(day) {}
}Smoke;

void Init();
void Input();
void Solve();
int GetNextDir(const int y, const int x, const int shark_idx, const vector<int>& dirs);


const int MAX = 1e9;
int n, m, k; // 격자의 크기, 상어는 m마리, 냄새가 사라지는 횟수
int dy[] = {-1, 1, 0, 0}; // 위, 아래, 왼쪽, 오른쪽
int dx[] = {0, 0, -1, 1};
vector<vector<deque<int> > > board;
vector<vector<deque<int> > > smoke;
vector<bool> isOut;
vector<Shark> sharks;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m >> k;

    board.resize(n, vector<deque<int> >(n, deque<int>()));
    smoke.resize(n, vector<deque<int> >(n, deque<int>()));
    isOut.resize(m+1, false);
    sharks.reserve(m+1);

    vector<pair<int, int > > cur_loc(m+1, {0, 0});
    vector<int> cur_dir(m+1, 0); // 현재 상어의 방향

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int shark_idx;
            cin >> shark_idx;
            if(shark_idx != 0){
                cur_loc[shark_idx] = {i, j};
                board[i][j].emplace_back(shark_idx);
            }
        }
    }

    for(int i=1; i<=m; i++){
        cin >> cur_dir[i];
        cur_dir[i]--;
    }

    for(int i=1; i<=m; i++){
        vector<vector<int> > dirs(4, vector<int>(4, 0));
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cin >> dirs[j][k];
                dirs[j][k]--;
            }
        }
        sharks[i] = Shark(cur_loc[i].first, cur_loc[i].second, cur_dir[i], dirs);
    }
}

void Solve()
{
    int day = 1;
    queue<Smoke> smokeQ;

    while(1){
        // 자신의 위치에 냄새를 뿌린다.
        for(int i=1; i<=m; i++){
            if(isOut[i]) continue;

            int y = sharks[i].y;
            int x = sharks[i].x;
            smoke[y][x].emplace_back(i);
            smokeQ.push(Smoke(y, x, i, day + k));
        }

        // 모든 상어가 "동시에" 이동한다.
        for(int i=1; i<=m; i++){
            if(isOut[i]) continue;

            int y = sharks[i].y;
            int x = sharks[i].x;
            int dir = sharks[i].dir; // 현재 방향
            int next_dir = GetNextDir(y, x, i, sharks[i].dirs[dir]);

            int ny = y + dy[next_dir];
            int nx = x + dx[next_dir];
            // board에서 제거, 추가
            board[y][x].erase(remove(board[y][x].begin(), board[y][x].end(), i), board[y][x].end());
            board[ny][nx].emplace_back(i);
            // shakrs에서 수정
            sharks[i].dir = next_dir;
            sharks[i].y = ny;
            sharks[i].x = nx;
        }

        // 상어를 쫓아낸다
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j].size() > 1){
                    int survivor = 1e9;

                    for(int k=0; k<board[i][j].size(); k++){
                        if(isOut[board[i][j][k]]) continue;
                        survivor = min(survivor, board[i][j][k]);
                    }

                    for(int k=0; k<board[i][j].size(); k++){
                        int shark_idx = board[i][j][k];
                        if(isOut[shark_idx]) continue;

                        if(survivor != shark_idx){
                            isOut[shark_idx] = true;
                        }
                    }

                    board[i][j].clear();
                    board[i][j] = {survivor};
                }
            }
        }

        // 냄새가 사라진다.
        while(!smokeQ.empty() && smokeQ.front().day <= day){
            int y = smokeQ.front().y;
            int x = smokeQ.front().x;
            int idx = smokeQ.front().idx;
            smokeQ.pop();
            for(int i=0; i<smoke[y][x].size(); i++){
                if(smoke[y][x][i] == idx){
                    smoke[y][x].erase(smoke[y][x].begin() + i);
                    break;
                }
            }
            // smoke[y][x].erase(remove(smoke[y][x].begin(), smoke[y][x].end(), idx), smoke[y][x].end());
        }
        // 1번 상어만 살아남았는지 검사한다.
        bool isEnd = true;
        for(int i=2; i<=m; i++){
            if(!isOut[i]){
                isEnd = false;
                break;
            }
        }
        if(isEnd){
            cout << day;
            return;
        }
        day++;

        if(day > 1000){
            cout << -1;
            return;
        }
    }
}

int GetNextDir(const int y, const int x, const int shark_idx, const vector<int>& dirs){
    // 냄새가 없는 곳
    for(int i=0; i<4; i++){
        int ny = y + dy[dirs[i]];
        int nx = x + dx[dirs[i]];
        if(0 <= ny && ny < n && 0 <= nx && nx < n){
            if(smoke[ny][nx].size() == 0) return dirs[i];
        }
    }
    // 자신의 냄새가 있는 곳
    for(int i=0; i<4; i++){
        int ny = y + dy[dirs[i]];
        int nx = x + dx[dirs[i]];
        if(0 <= ny && ny < n && 0 <= nx && nx < n){
            for(int j=0; j<smoke[ny][nx].size(); j++){
                if(smoke[ny][nx][j] == shark_idx) return dirs[i];
            }
        }
    }
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}