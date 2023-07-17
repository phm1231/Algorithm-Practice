// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct shark{
    int speed, d, siz;
    shark(int speed, int d, int siz): speed(speed), d(d), siz(siz) {}
}shark;

void init();
void input();
void solve();
int catchShark(int x);
void move();
void eat();
pair<int, pair<int, int> > getNextLocation(int y, int x, shark sh);

int n, m, t;
// 상 하 우 좌
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<vector<vector<shark> > > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> t;
    bd.resize(n+1, vector<vector<shark> >(m+1, vector<shark>()));

    for(int i=0; i<t; i++){
        int y, x, s, d, siz;
        cin >> y >> x >> s >> d >> siz;
        bd[y][x].push_back(shark(s, d-1, siz));
    }
}

void solve()
{
    // 낚시왕이 이동한다
    int answer = 0;
    for(int fisher=1; fisher<=m; fisher++){
        // 상어를 잡는다
        answer += catchShark(fisher);
        move();
        eat();
    }
    cout << answer;

}

void move(){
    vector<vector<vector<shark> > >  tmpbd(n+1, vector<vector<shark> >(m+1, vector<shark>()));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // 상어가 있다면
            if(bd[i][j].size() > 0){
                shark s = bd[i][j][0];
                pair<int, pair<int, int> > info = getNextLocation(i, j, s);
                int dir = info.first;
                int ny = info.second.first;
                int nx = info.second.second;
                tmpbd[ny][nx].push_back(shark(s.speed, dir, s.siz));
            }
        }
    }
    bd = tmpbd;
}

void eat(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(bd[i][j].size() > 1){
                shark sharkKing = bd[i][j][0];
                for(int k=1; k<bd[i][j].size(); k++){
                    if(sharkKing.siz < bd[i][j][k].siz){
                        sharkKing = bd[i][j][k];
                    }
                }
                while(bd[i][j].size() != 0) bd[i][j].pop_back();
                bd[i][j].push_back(sharkKing);
            }
        }
    }
}


int catchShark(int x){
    int ret = 0;
    for(int y=1; y<=n; y++){
        if(bd[y][x].size() > 0){
            ret = bd[y][x][0].siz;
            bd[y][x].pop_back();
            return ret;
        }
    }
    return 0;
}

pair<int, pair<int, int> > getNextLocation(int y, int x, shark sh){
    pair<int, pair<int, int> > ret;
    int speed = sh.speed;
    int dir = sh.d;
    // 상하
    if(dir == 0 || dir == 1){
        speed = speed % ((n-1)*2);
        int here = y;
        while(speed--){
            int next = here + dy[dir];
            // 위를 뚫음
            if(next < 1) dir = 1;
            else if(next > n) dir = 0;

            next = here + dy[dir];
            here = next;
        }
        ret.first = dir;
        ret.second.first = here;
        ret.second.second = x;
    }
    // 좌우
    else{
        speed = speed % ((m-1) * 2);
        int here = x;
        while(speed--){
            int next = here + dx[dir];

            if(next < 1) dir = 2;
            else if(next > m) dir = 3;

            next = here + dx[dir];
            here = next;
        }
        ret.first = dir;
        ret.second.first = y;
        ret.second.second = here;
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
