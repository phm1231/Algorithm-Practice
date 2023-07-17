// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void diffusion();
void clean(int, int, int, bool);

int n, m, t;
pair<int, int> airCleaner;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> t;
    bd.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> bd[i][j];
            if(bd[i][j] == -1){
                airCleaner.first = i;
                airCleaner.second = j;
            }
        }
    }
}

void solve()
{
    while(t--){
        diffusion();
        clean(airCleaner.first - 1, airCleaner.second, 0, false);
        clean(airCleaner.first, airCleaner.second, 3, true);
    }
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer += bd[i][j];
        }
    }
    cout << answer + 2;
}

void diffusion(){
    vector<vector<int> > tmpbd(n, vector<int>(m, 0));
    tmpbd[airCleaner.first][airCleaner.second] = -1;
    tmpbd[airCleaner.first-1][airCleaner.second] = -1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 확산 가능하면
            if(bd[i][j] > 0){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(0 <= ny && ny < n && 0 <= nx && nx < m){
                        if(bd[ny][nx] == -1 || tmpbd[ny][nx] == -1) continue;

                        tmpbd[ny][nx] += (bd[i][j] / 5);
                        cnt++;
                    }
                }
                bd[i][j] -= (bd[i][j] / 5) * cnt;
                tmpbd[i][j] += bd[i][j];
            }
        }
    }
    bd = tmpbd;
}

void clean(int by, int bx, int d, bool isClock){
    int hy = by + dy[d];
    int hx = bx + dx[d];
    // 지금이 공기청정기라면
    if(bd[hy][hx] == -1) return;

    // 이전이 공기청정기라면
    if(bd[by][bx] != -1) bd[by][bx] = bd[hy][hx];
    bd[hy][hx] = 0;
    // hy와 by는 값이 유효하다고 증명됨.

    int ny = hy + dy[d];
    int nx = hx + dx[d];
    if(0 <= ny && ny < n && 0 <= nx && nx < m){
        // 위 공기청정기가 아래 공기청정기를 침범하게 되면 방향전환
        if(!isClock && ny >= airCleaner.first) clean(hy, hx, 1, isClock);
        // 아래 공기청정기가 위 공기청정기를 침범하게 되면 방향전환
        else if(isClock && ny <= airCleaner.first - 1) clean(hy, hx, 1, isClock);
        // 그대로 진행
        else clean(hy, hx, d, isClock);
    }
    else{
        if(d == 0) !isClock ? clean(hy, hx, 2, isClock) : clean(hy, hx, 1, isClock); // 위로 가다가 꺾음
        else if(d == 1) !isClock ? clean(hy, hx, 0, isClock) : clean(hy, hx, 3, isClock); // 좌로 가다가 꺾음
        else if(d == 2) !isClock ? clean(hy, hx, 3, isClock) : clean(hy, hx, 0, isClock); // 우로 가다가 꺾음
        else if(d == 3) !isClock ? clean(hy, hx, 1, isClock) : clean(hy, hx, 2, isClock); // 아래로 가다가 꺾음
    }

}

int main()
{
    init();
    input();
    solve();
    return 0;
}