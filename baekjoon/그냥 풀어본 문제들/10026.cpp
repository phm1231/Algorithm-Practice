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
void bfs(int, int, int);
void custombfs(int, int, int);

int n, p, q;
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int board[101][101];
int visited[101][101];

void bfs(int y, int x, int num){
    if(1 <= y && y <= n && 1 <= x && x <= n){
        queue<pair<int ,int> > myq;
        myq.push(make_pair(y, x));
        while(!myq.empty()){
            int _y = myq.front().first;
            int _x = myq.front().second;
            myq.pop();

            for(int i=0; i<4; i++){
                int ny = _y + dy[i];
                int nx = _x + dx[i];
                if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
                    if(board[ny][nx] == board[y][x] && visited[ny][nx] == 0){
                        visited[ny][nx] = num;
                        myq.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }
}

void custombfs(int y, int x, int num){
    if(1 <= y && y <= n && 1 <= x && x <= n){
        queue<pair<int ,int> > myq;
        myq.push(make_pair(y, x));
        while(!myq.empty()){
            int _y = myq.front().first;
            int _x = myq.front().second;
            myq.pop();

            for(int i=0; i<4; i++){
                int ny = _y + dy[i];
                int nx = _x + dx[i];
                if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
                    if(board[y][x] == 1 || board[y][x] == 2){
                        if(visited[ny][nx] == 0 && (board[ny][nx] == 1 || board[ny][nx] == 2)){
                            visited[ny][nx] = num;
                            myq.push(make_pair(ny, nx));
                        }
                    }
                    else if(board[y][x] == 3){
                        if(visited[ny][nx] == 0 && (board[ny][nx] == board[y][x])){
                            visited[ny][nx] = num;
                            myq.push(make_pair(ny, nx));

                        }
                    }
                }
            }
        }
    }
}

void init()
{
    FAST
    memset(board, 0, sizeof(board));
    memset(visited, 0, sizeof(visited));
    p = 0;
    q = 0;
}

void input()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=1; j<=n; j++){
            char ch = str[j-1];
            switch(ch){
                case 'R':
                    board[i][j] = 1;
                    break;
                case 'G':
                    board[i][j] = 2;
                    break;
                case 'B':
                    board[i][j] = 3;
                    break;
            }
        }
    }
}

void solve()
{
    // 적록색맹 아닌 사람
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j] == 0){
                p++;
                bfs(i, j, p);
            }
        }
    }
    // 적록색맹인 사람
    memset(visited, 0, sizeof(visited));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j] == 0){
                q++;
                custombfs(i, j, q);
            }
        }
    }
    cout << p << ' ' << q;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}