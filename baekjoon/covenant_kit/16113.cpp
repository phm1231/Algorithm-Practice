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
int getNumber(int, int);

int n, h, w;
string signal;
vector<vector<bool> > board;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};

// 1을 제외한 모든 숫자들은 3칸을 차지한다.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> signal;
}

void solve()
{
    string result = "";

    h = 5;
    w = n / h;
    board.resize(h, vector<bool>(w, false));

    for(int i=0; i<signal.size(); i++){
        int x = i % w;
        int y = i / w;
        board[y][x] = (signal[i] == '#'); // #이면 true
    }

    for(int i=0; i<w; i++){
        if(!board[0][i]) continue;
        int res = getNumber(0, i);
        if(res == -1) continue;
        if(res != 1) i+=2;
        result += to_string(res);
    }
    cout << result << endl;
}

int getNumber(int sy, int sx){
    int b_cnt = 1;
    queue<pair<int, int> > q;
    q.push({sy, sx});
    vector<vector<bool> > visited(5, vector<bool>(3, false));
    visited[0][0] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny - sy && ny - sy < 5 && 0 <= nx - sx && nx - sx < 3){
                if(board[ny][nx] && !visited[ny-sy][nx-sx]){
                    visited[ny-sy][nx-sx] = true;
                    b_cnt++;
                    q.push({ny, nx});
                }
            }
        }
    }


    if(b_cnt == 13) return 8;
    if(b_cnt == 9) return 4;
    if(b_cnt == 7) return 7;
    if(b_cnt == 5) return 1;

    if(b_cnt == 12){
        // 0, 6, 9 중 하나
        if(board[sy+1][sx+2] && board[sy+3][sx]) return 0;
        if(!board[sy+1][sx+2] && board[sy+3][sx]) return 6;
        if(board[sy+1][sx+2] && !board[sy+3][sx]) return 9;
    }
    if(b_cnt == 11){
        // 2, 3, 5 중 하나
        if(!board[sy+1][sx] && board[sy+3][sx]) return 2;
        if(!board[sy+1][sx] && !board[sy+3][sx]) return 3;
        if(board[sy+1][sx] && !board[sy+3][sx]) return 5;
    }

    return -1;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}