#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

#define ll long long
#define MAX 100001

using namespace std;

typedef struct horse{
    int y, x, d, num;
    horse(int y, int x, int d, int num): y(y), x(x), d(d), num(num) {}
}horse;

void init();
void input();
void solve();
bool white(int i, int y, int x, int ny, int nx);
bool red(int i, int y, int x, int ny, int nx);
void check();

int n, k;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
vector<vector<int> > board;
vector<vector<deque<horse> > > v;
vector<horse> horses;

void check(){
    cout << "CHECK\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<v[i][j].size(); k++){
                if(k == 0) cout << i << ", " << j << "\n";
                cout << v[i][j][k].num << ' ';
                if(k == v[i][j].size() - 1) cout << "\n";
            }
        }
    }
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    board.resize(n, vector<int>(n, 0));
    v.resize(n, vector<deque<horse> >(n, deque<horse>()));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int y, x, d;
        cin >> y >> x >> d;
        y--, x--, d--;
        horses.push_back(horse(y, x, d, i));
        v[y][x].push_back(horse(y, x, d, i));
    }
}

void solve()
{

    int turn = 0;
    while(1){
        // check();
        if(turn > 1000){
            cout << -1;
            return;
        }

        turn++;
        for(int i=0; i<k; i++){
            int y = horses[i].y;
            int x = horses[i].x;
            int d = horses[i].d;
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                // 흰색
                if(board[ny][nx] == 0){
                    if(!white(i, y, x, ny, nx)){
                        cout << turn;
                        return;
                    }
                    continue;
                }

                // 빨간색
                else if(board[ny][nx] == 1){
                    if(!red(i, y, x, ny, nx)){
                        cout << turn;
                        return;
                    }
                    continue;
                }
            }

            // 범위에 속하지 않거나, 파란색.
            if(!(0 <= ny && ny < n && 0 <= nx && nx < n) || board[ny][nx] == 2){
                // 방향을 반대로 한다.
                int nd;
                if(d == 0) nd = 1;
                else if(d == 1) nd = 0;
                else if(d == 2) nd = 3;
                else if(d == 3) nd = 2;

                horses[i].d = nd;

                // 한 칸 이동한다.
                ny = y + dy[nd];
                nx = x + dx[nd];
                if(0 <= ny && ny < n && 0 <= nx && nx < n){
                    if(board[ny][nx] == 0){
                        if(!white(i, y, x, ny, nx)){
                            cout << turn;
                            return;
                        }
                        continue;
                    }
                    else if(board[ny][nx] == 1){
                        if(!red(i, y, x, ny, nx)){
                            cout << turn;
                            return;
                        }
                        continue;
                    }
                }
                // 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
                if(!(0 <= ny && ny < n && 0 <= nx && nx < n) || board[ny][nx] == 2){
                    continue;
                }
            }
        }
    }
}

bool white(int i, int y, int x, int ny, int nx){
    stack<horse> stk;
    // 한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다.
    while(!v[y][x].empty()){
        horse h = v[y][x].back();
        v[y][x].pop_back();
        stk.push(h);

        if(h.num == horses[i].num) break;
    }
    // ny, nx로 이동시킨다.
    while(!stk.empty()){
        horse h = stk.top();
        stk.pop();
        v[ny][nx].push_back(h);
        horses[h.num].y = ny;
        horses[h.num].x = nx;
    }
    return v[ny][nx].size() < 4;
}

bool red(int i, int y, int x, int ny, int nx){
    deque<horse> dq;
    // 한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다.
    while(!v[y][x].empty()){
        horse h = v[y][x].back();
        v[y][x].pop_back();
        dq.push_back(h);

        if(h.num == horses[i].num) break;
    }
    // ny, nx로 이동시킨다.
    while(!dq.empty()){
        horse h = dq.front();
        dq.pop_front();
        v[ny][nx].push_back(h);
        horses[h.num].y = ny;
        horses[h.num].x = nx;
    }
    return v[ny][nx].size() < 4;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}