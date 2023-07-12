// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

// 1 이면 4방향
// 2 이면 2방향
// 3 이면 4방향
// 4 이면 4방향
// 5 이면 1방향

typedef struct cctv{
    int y, x, num, d;
    cctv(int y, int x, int num, int d): y(y), x(x), num(num), d(d) {}
}cctv;

void init();
void input();
void solve();
void dfs(int idx, vector<cctv>& v);
void check(vector<cctv>& v);
void onCCTV(int y, int x, int d, vector<vector<int> >& tmpbd);

int n, m;
int answer;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
vector<cctv> cctvs;
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    answer = n*m;
    bd.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
            if(bd[i][j] != 0 && bd[i][j] != 6) cctvs.push_back(cctv(i, j, bd[i][j], 0));
        }
    }
}

void solve()
{
    vector<cctv> v;
    dfs(0, v);
    cout << answer;
}

void dfs(int idx, vector<cctv>& v){
    if(idx == cctvs.size()){
        check(v);
        return;
    }
    if(cctvs[idx].num == 1 || cctvs[idx].num == 3 || cctvs[idx].num == 4){
        for(int i=0; i<4; i++){
            v.push_back(cctv(cctvs[idx].y, cctvs[idx].x, cctvs[idx].num, i));
            dfs(idx+1, v);
            v.pop_back();
        }
    }
    else if(cctvs[idx].num == 2){
        for(int i=0; i<2; i++){
            v.push_back(cctv(cctvs[idx].y, cctvs[idx].x, cctvs[idx].num, i));
            dfs(idx+1, v);
            v.pop_back();
        }
    }
    else if(cctvs[idx].num == 5){
        v.push_back(cctv(cctvs[idx].y, cctvs[idx].x, cctvs[idx].num, 0));
        dfs(idx+1, v);
        v.pop_back();
    }
}

void check(vector<cctv>& v){
    vector<vector<int> > tmpbd = bd;

    for(cctv c: v){
        if(c.num == 1){ // d 한 방향
            onCCTV(c.y, c.x, c.d, tmpbd);
        }
        else if(c.num == 2){ // 양극 방향
            onCCTV(c.y, c.x, c.d, tmpbd);
            onCCTV(c.y, c.x, c.d+2, tmpbd);
        }
        else if(c.num == 3){ // 직각 방향
            onCCTV(c.y, c.x, c.d, tmpbd);
            onCCTV(c.y, c.x, c.d+1, tmpbd);
        }
        else if(c.num == 4){ // 세방향
            onCCTV(c.y, c.x, c.d, tmpbd);
            onCCTV(c.y, c.x, c.d+1, tmpbd);
            onCCTV(c.y, c.x, c.d+2, tmpbd);
        }
        else if(c.num == 5){ // 모든 방향
            onCCTV(c.y, c.x, c.d, tmpbd);
            onCCTV(c.y, c.x, c.d+1, tmpbd);
            onCCTV(c.y, c.x, c.d+2, tmpbd);
            onCCTV(c.y, c.x, c.d+3, tmpbd);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmpbd[i][j] == 0) cnt++;
        }
    }
    answer = min(answer, cnt);
}

void onCCTV(int y, int x, int d, vector<vector<int> >& tmpbd){
    d %= 4;
    for(int j=1; ; j++){
        int ny = y + dy[d] * j;
        int nx = x + dx[d] * j;
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(tmpbd[ny][nx] == 0) tmpbd[ny][nx] = 9;
            else if(tmpbd[ny][nx] == 6) break;
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