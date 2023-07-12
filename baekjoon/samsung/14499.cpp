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

int n, m, y, x, k;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
vector<vector<int> > board;
queue<int> q;
vector<int> dice(6, 0);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> y >> x >> k;
    board.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
}

void solve()
{
    while(!q.empty()){
        int cmd = q.front() - 1;
        q.pop();

        int ny = y + dy[cmd];
        int nx = x + dx[cmd];
        // 보드 밖으로 나가지 않는다면
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            // 굴린다.
            int tmp = dice[0];
            // 동
            if(cmd == 0){
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[2];
                dice[2] = tmp;
            }
            // 서
            else if(cmd == 1){
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[4];
                dice[4] = tmp;
            }
            // 남
            else if(cmd == 2){
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = tmp;
            }
            // 북
            else if(cmd == 3){
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
            }

            if(board[ny][nx] == 0) board[ny][nx] = dice[5];
            else {
                dice[5] = board[ny][nx];
                board[ny][nx] = 0;
            }
            y = ny;
            x = nx;
            cout << dice[0] << "\n";
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