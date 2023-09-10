#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

typedef struct fish{
    int y, x, num, dir;
    fish(int y, int x, int num, int dir): y(y), x(x), num(num), dir(dir) {}
}fish;

void init();
void input();
void solve();
vector<vector<int> > move(const fish& shark, const vector<vector<int> >& bd, const vector<bool>& isDie, vector<fish>& fs);
void dfs(fish shark, vector<vector<int> > bd, vector<bool> isDie, vector<fish> fs);

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int answer = 0;

vector<fish> fishes;
vector<vector<int> > board; // board[i][j] = k, k번 물고기가 위치해있음.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    board.resize(4, vector<int>(4, 0));
    fishes.resize(17, fish(0, 0, 0, 0));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b;
            cin >> a >> b;
            fishes[a] = fish(i, j, a, b - 1);
            board[i][j] = a;
        }
    }
}

void solve()
{
    int y = 0;
    int x = 0;


    vector<fish> fs = fishes; // fs[i] = i번 물고기의 정보
    
    int hunted_fish = board[0][0];

    // 먹어서 상어를 배치한다.
    vector<bool> isDie(17, false);
    isDie[hunted_fish] = true; // isDie[i] = i번 물고기가 살아있는지.

    fish killed_fish = fs[hunted_fish];    
    fish shark = fish(0, 0, hunted_fish, killed_fish.dir); // 상어 배치

    // 물고기를 움직인다
    vector<vector<int> > curbd = move(shark, board, isDie, fs);

    // 상어가 다음 먹잇감을 찾아서 먹을 것.
    for(int i=1; ; i++){
        int ny = y + (dy[shark.dir] * i);
        int nx = x + (dx[shark.dir] * i);
        if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
            int hunted = curbd[ny][nx];
            if(isDie[hunted]) continue;

            isDie[hunted] = true;
            fish next_shark = fish(ny, nx, shark.num + hunted, fs[hunted].dir);
            dfs(next_shark, curbd, isDie, fs);
            isDie[hunted] = false;

        }
        else break;
    }

    cout << answer;
}

void dfs(fish shark, vector<vector<int> > bd, vector<bool> isDie, vector<fish> fs){
    answer = max(answer, shark.num);

    vector<vector<int> > curbd = move(shark, bd, isDie, fs);

    // 상어가 다음 먹잇감을 찾아서 먹을 것.
    for(int i=1; ; i++){
        int ny = shark.y + (dy[shark.dir] * i);
        int nx = shark.x + (dx[shark.dir] * i);
        if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
            int hunted = curbd[ny][nx];
            if(isDie[hunted]) continue;

            isDie[hunted] = true;

            fish next_shark = fish(ny, nx, shark.num + hunted, fs[hunted].dir);
            dfs(next_shark, curbd, isDie, fs);

            isDie[hunted] = false;
        }
        else break;
    }
}


vector<vector<int> > move(const fish& shark, const vector<vector<int> >& bd, const vector<bool>& isDie, vector<fish>& fs){
    vector<vector<int> > ret = bd;

    for(int i=1; i<=16; i++){
        if(isDie[i]) continue;

        fish f = fs[i];
        int y = f.y;
        int x = f.x;
        int _dir = f.dir;

        for(int d=0; d<8; d++){
            int dir = (d + _dir) % 8;

            int ny = y + dy[dir];
            int nx = x + dx[dir];
    
            if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
                // 상어이면
                if(ny == shark.y && nx == shark.x) continue;


                int j = ret[ny][nx]; // 바꿀 물고기.
                // i번 물고기는 ny, nx로 이동하고, 새로운 방향을 가진다.
                fs[i] = fish(ny, nx, i, dir);
                // j번 물고기는 y, x로 이동하고, 기존 방향을 유지한다.
                fs[j] = fish(y, x, j, fs[j].dir);
                
                ret[ny][nx] = i;
                ret[y][x] = j;
                break;
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