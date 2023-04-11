// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n, m;
int visited[1001][1001][2];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

vector<string> board;

void init()
{
    FAST
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            for(int k=0; k<2; k++){
                visited[i][j][k] = 987654321;
            }
        }
    }
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        board.push_back(str);
    }
}

void solve()
{
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0][0] = visited[0][0][1] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == '0'){
                    // 부수지 않고 0에서 0으로
                    if(visited[ny][nx][0] > visited[y][x][0] + 1){
                        visited[ny][nx][0] = visited[y][x][0] + 1;
                        q.push(make_pair(ny, nx));
                    }
                    // 이전에 벽을 한 번 부쉈었고, 0으로
                    if(visited[ny][nx][1] > visited[y][x][1] + 1){
                        visited[ny][nx][1] = visited[y][x][1] + 1;
                        q.push(make_pair(ny, nx));
                    }
                }
                else if(board[ny][nx] == '1'){
                    // 벽을 부수지 않았을 때만
                    if(visited[ny][nx][1] > visited[y][x][0] + 1){
                        visited[ny][nx][1] = visited[y][x][0] + 1;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }
    if(visited[n-1][m-1][0] == 987654321 && visited[n-1][m-1][1] == 987654321) cout << -1;
    else cout << min(visited[n-1][m-1][0] + 1, visited[n-1][m-1][1] + 1);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}