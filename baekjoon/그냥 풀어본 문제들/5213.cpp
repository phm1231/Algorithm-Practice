#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void print();
int getX(int y, int x);
int getArea(int y, int x);

int n, lastArea, maxArea;
vector<int> path;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<vector<int> > board;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    board.resize(n, vector<int>(2*n, 0));
    visited.resize(n, vector<bool>(2*n, false));
    maxArea = 0;
    lastArea = n * n - n / 2;

    for(int i=0; i<n; i++){
        // 짝수줄이면 타일이 n개
        if(i % 2 == 0){
            for(int j=0; j<2*n; j++){
                cin >> board[i][j];
            }
        }
        // 홀수줄이면 타일이 n-1개
        else{
            for(int j=1; j<2*n-1; j++){
                cin >> board[i][j];
            }
        }
    }
}

void solve()
{
    queue<pair<vector<int>, pair<int, int> > > q;
    vector<int> tmp;
    visited[0][0] = visited[0][1] = true;
    q.push(make_pair(tmp, make_pair(0, 0)));

    while(!q.empty()){
        vector<int> v = q.front().first;
        int y1 = q.front().second.first;
        int x1 = q.front().second.second;
        int y2 = y1;
        int x2 = getX(y1, x1);
        q.pop();

        visited[y2][x2] = true;
        int area = getArea(y1, x1);
        v.push_back(area);

        if(area == lastArea){
            maxArea = lastArea;
            path = v;
            break;
        }
        if(maxArea < area){
            maxArea = area;
            path = v;
        }

        // y1, x1쌍에 대해서
        for(int i=0; i<4; i++){
            int ny = y1 + dy[i];
            int nx = x1 + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < 2*n){
                // 존재하지 않는 타일임.
                if(board[ny][nx] == 0) continue;
                // 이미 방문한 적이 있는 타일임.
                if(visited[ny][nx]) continue;
                // 동일한 타일임.
                if(ny == y2 && nx == x2) continue;
                // 넘어갈 수 있다면
                if(board[y1][x1] == board[ny][nx]){
                    visited[ny][nx] = true;
                    q.push(make_pair(v, make_pair(ny, nx)));
                }
            }
        }
        // y2, x2쌍에 대해서
        for(int i=0; i<4; i++){
            int ny = y2 + dy[i];
            int nx = x2 + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < 2*n){
                // 존재하지 않는 타일임.
                if(board[ny][nx] == 0) continue;
                // 이미 방문한 적이 있는 타일임.
                if(visited[ny][nx]) continue;
                // 동일한 타일임.
                if(ny == y1 && nx == x1) continue;
                // 넘어갈 수 있다면
                if(board[y2][x2] == board[ny][nx]){
                    visited[ny][nx] = true;
                    q.push(make_pair(v, make_pair(ny, nx)));
                }
            }
        }
    }
    cout << path.size() << endl;
    for(int item: path) cout << item << ' ';
}

int getX(int y, int x){
    // y가 짝수이면 
    if(y % 2 == 0){
        if(x % 2 == 0) return x + 1;
        else return x - 1;
    }
    // y가 홀수
    else{
        if(x % 2 == 0) return x - 1;
        else return x + 1;
    }
}

int getArea(int y, int x){
    if(y % 2 == 0) return y * n + x / 2  + 1 - (y / 2);
    else return y * n + (x - 1) / 2 + 1 - (y / 2);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}