#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
void Dfs(const int y, const int x, const int d1, const int d2);
void getAnswer(const vector<int>& sums);

int n;
int dy[] = {1, 1};
int dx[] = {-1, 1};
int answer = 1e9;
int sumofBoard = 0;
vector<vector<int> > board;
bool visited[21][21][21][21] = {false, };

// 기준점 y, x를 정하고 경계의 길이 d1, d2를 정한다.

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            sumofBoard += board[i][j];
        }
    }
}

void Solve()
{

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j][1][1] = true;
            Dfs(i, j, 1, 1);
        }
    }
    cout << answer << endl;
}

void Dfs(const int y, const int x, const int d1, const int d2){
    if(y >= n || x >= n || d1 >= n || d2 >= n) return;

    visited[y][x][d1][d2] = true;
    vector<int> sums = {0, 0, 0, 0, sumofBoard};
    vector<vector<int> > check(n, vector<int>(n, 0));
    int w = 0;

    // 1구역 계산
    for(int i=0; i<y+d1; i++){ // 세로 범위 맞음.
        if(y <= i && i <= y + d1) w++; // 겹친다면 범위를 줄여주기.
        for(int j=0; j<=x-w; j++){ // 가로 범위 맞음.
            if(i < 0 || i >= n || j < 0 || j >= n) return;
            sums[0] += board[i][j];
            check[i][j] = 1;
        }
    }

    w = 0;
    // 2구역 계산
    for(int i=0; i<=y+d2; i++){ // 세로 범위 맞음.
        for(int j=x+1+w; j<n; j++){ // 가로 범위 맞음.
            if(i < 0 || i >= n || j < 0 || j >= n) return;
            sums[1] += board[i][j];
            check[i][j] = 2;
        }
        if(y <= i && i <= y + d2) w++; // 겹친다면 범위를 늘려주기.
    }

    w = 0;
    // 3구역 계산
    for(int i=y+d1; i<n; i++){ // 세로 범위 맞음
        for(int j=0; j<x-d1+w; j++){ // 가로 범위 맞음
            if(i < 0 || i >= n || j < 0 || j >= n) return;
            sums[2] += board[i][j];
            check[i][j] = 3;
        }
        if(i < y+d1+d2) w++;
    }
    w = 0;
    // 4구역 계산
    for(int i=y+d2+1; i<n; i++){
        for(int j=x+d2-w; j<n; j++){
            if(i < 0 || i >= n || j < 0 || j >= n) return;
            sums[3] += board[i][j];
            check[i][j] = 4;
        }
        if(i <= y+d1+d2) w++;
    }
    // 5구역 계산
    for(int i=0; i<4; i++) sums[4] -= sums[i];

    getAnswer(sums);
    
    if(!visited[y][x][d1+1][d2]) Dfs(y, x, d1 + 1, d2);
    if(!visited[y][x][d1][d2+1]) Dfs(y, x, d1, d2 + 1);
    if(!visited[y][x][d1+1][d2+1]) Dfs(y, x, d1 + 1, d2 + 1);
}

void getAnswer(const vector<int>& sums){
    // 최소, 최댓값 구하기
    int minimum = 1e9; // 가장 적은 선거구
    int maximum = -1; // 가장 많은 선거구
    for(int i=0; i<5; i++){
        minimum = min(minimum, sums[i]);
        maximum = max(maximum, sums[i]);
    }
    answer = min(answer, maximum - minimum); // 인구 사이의 최솟값
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}