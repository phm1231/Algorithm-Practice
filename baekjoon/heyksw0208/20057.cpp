// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void go(int y, int x, int d);

int n;
int answer = 0;
int ws1[] = {10, 7, 1, 10, 7, 1, 5, 2, 2};
int ws2[] = {1, 7, 10, 1, 7, 10, 5, 2, 2};

int d1[] = {-1, -1, -1, 1, 1, 1, 0, -2, 2};
int d2[] = {-1, 0, 1, -1, 0, 1, -2, 0, 0};

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

// x축으로 움직였을 경우, 즉 i가 짝수일 경우 d1 = dy, d2 = dx
    // x가 감소했을 때(d = 0), [6]은 그대로, 증가했다면(d = 2) -를 곱해준다
    // x가 감소했을 때, ws1을, 증가했다면 ws2를 사용한다.

// y축으로 움직였을 경우, 즉 i가 홀수일 경우 d1 = dx, d2 = dy
    // y가 감소했을 때(d = 3), [6]은 그대로, 증가했다면(d = 1) -를 곱해준다.
    // y가 감소했을 때, ws1을, 증가했다면 ws2를 사용한다.
vector<vector<int> > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    bd.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    int w = 1;
    int y = n / 2;
    int x = n / 2;
    int d = 0;
    while(!(y == 0 && x == 0)){
        d %= 4; // 방향 결정

        // 해당 방향으로 한 칸씩 나아가면서 처리한다.
        for(int i=0; i<w; i++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            // d 방향으로 토네이도가 이동한다.
            go(ny, nx, d);

            // [ny][nx]의 남은 모래가 한 칸 앞쪽으로 이동한다.
            int nny = ny + dy[d];
            int nnx = nx + dx[d];
            if(0 <= nny && nny < n && 0 <= nnx && nnx < n) bd[nny][nnx] += bd[ny][nx];
            else answer += bd[ny][nx];
            bd[ny][nx] = 0;

            y = ny;
            x = nx;            
            if(y == 0 && x == 0) break;
        }
        
        if(d % 2 == 1) w++;

        d++; // 방향 전환
    }

    cout << answer;

}

void go(int y, int x, int d){
    // 좌로 움직임, d1 = dy, d2 = dx, x가 감소했으므로 ws1
    int moved = 0; // 바람의 영향을 받아 날아간 모래의 양

    if(d == 0){
        // 토네이도로 날림.
        for(int i=0; i<9; i++){
            int ny = y + d1[i];
            int nx = x + d2[i];

            int wind = (bd[y][x] * ws1[i]) / 100; // 바람이 불어서 날아가는 양.
            moved += wind;
            // 범위 안이라면
            if(0 <= ny && ny < n && 0 <= nx && nx < n) bd[ny][nx] += wind;
            else answer += wind;
        }
    }
    // 아래로 움직임, d1 = dx, d2 = dy y가 증가했으므로 ws2
    else if(d == 1){
        for(int i=0; i<9; i++){
            int ny = y + d2[i];
            int nx = x + d1[i];
            if(i == 6) ny = y + (d2[i] * -1);
            
            int wind = (bd[y][x] * ws2[i]) / 100; // 바람이 불어서 날아가는 양.
            moved += wind;

            // 범위 안이라면
            if(0 <= ny && ny < n && 0 <= nx && nx < n) bd[ny][nx] += wind;
            else answer += wind;
        }        
    }
    // 우로 움직임, d1 = dy, d2 = dx, x가 증가했으므로 ws2
    else if(d == 2){
        for(int i=0; i<9; i++){
            int ny = y + d1[i];
            int nx = x + d2[i];
            if(i == 6) nx = x + (d2[i] * -1);

            int wind = (bd[y][x] * ws2[i]) / 100; // 바람이 불어서 날아가는 양.
            moved += wind;

            // 범위 안이라면
            if(0 <= ny && ny < n && 0 <= nx && nx < n) bd[ny][nx] += wind;
            else answer += wind;
        }
    }
    // 위로 움직임, d1 = dx, d2 = dy, y가 감소했으므로 ws1
    else if(d == 3){
        for(int i=0; i<9; i++){
            int ny = y + d2[i];
            int nx = x + d1[i];
            
            int wind = (bd[y][x] * ws1[i]) / 100; // 바람이 불어서 날아가는 양.
            moved += wind;
            // 범위 안이라면
            if(0 <= ny && ny < n && 0 <= nx && nx < n) bd[ny][nx] += wind;
            else answer += wind;
        }
    }
    // 날아간 모래 처리
    bd[y][x] -= moved;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}