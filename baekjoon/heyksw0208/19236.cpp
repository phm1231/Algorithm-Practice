// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct shark{
    int y, x, d;
    shark(int y, int x, int d): y(y), x(x), d(d) {}
}shark;


void init();
void input();
void solve();
void dfs(vector<vector<int> > bd, vector<shark> f, vector<bool> isAlive, shark s, int sum);

vector<vector<int> > board;
vector<shark> fishes;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int answer = 0;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    board.resize(4, vector<int>(4, 0));
    fishes.resize(17, shark(0, 0, 0));

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b;
            cin >> a >> b;
            board[i][j] = a; // bd[i][j]에는 a번 물고기가 있다.
            fishes[a] = shark(i, j, b-1);
        }
    }

}

void solve()
{
    vector<bool> isAlive(17, true);

    shark s = fishes[board[0][0]];
    answer = board[0][0];
    isAlive[board[0][0]] = false;
    board[0][0] = -1;

    dfs(board, fishes, isAlive, s, answer);

    cout << answer;
}

void dfs(vector<vector<int> > bd, vector<shark> f, vector<bool> isAlive, shark s, int sum){

    answer = max(answer, sum);
    // 물고기 이동
    for(int fish=1; fish<=16; fish++){
        if(!isAlive[fish]) continue; // 이미 먹힌 물고기

        // 살아있는 물고기라면 방향을 갖고 이동한다.
        int dir = f[fish].d;
        int y = f[fish].y;
        int x = f[fish].x;

        for(int d=0; d<8; d++){
            int ny = y + dy[(dir + d) % 8];
            int nx = x + dx[(dir + d) % 8];
            if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
                // 상어가 있는 곳으로는 이동할 수 없다.
                if(s.y == ny && s.x == nx) continue;

                if(bd[ny][nx] == -1){
                    f[fish] = shark(ny, nx, (dir + d) % 8);

                    bd[y][x] = -1;
                    bd[ny][nx] = fish;

                    break;
                }

                // 다른 물고기가 있다면 자리를 바꾼다
                // fish가 ny, nx로 현재 방향을 유지하며 이동
                // [ny][nx]에 있던 fish는 방향을 유지하고 위치만 변경
                if(bd[ny][nx] != -1){
                    f[fish] = shark(ny, nx, (dir + d) % 8);
                    f[bd[ny][nx]].y = y;
                    f[bd[ny][nx]].x = x;

                    bd[y][x] = bd[ny][nx];
                    bd[ny][nx] = fish;

                    break;
                }
            }
        }
    }

    // 상어의 식사
    for(int i=1; ; i++){
        int ny = s.y + dy[s.d] * i;
        int nx = s.x + dx[s.d] * i;
        if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
            if(bd[ny][nx] != -1){
                int fishNum = bd[ny][nx];

                bd[ny][nx] = -1;
                isAlive[fishNum] = false;
                dfs(bd, f, isAlive, f[fishNum], sum + fishNum);
                isAlive[fishNum] = true;
                bd[ny][nx] = fishNum;
                
            }
            else continue;
        }
        else break;
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}