// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void swanBFS();
void waterBFS();

int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
pair<int, int> swan;
vector<string> board;
vector<vector<bool> > visited;
bool isFind;

queue<pair<int, int> > Q, NQ, swanQ, swanNQ;
// swanQ에는 현재 백조가 갈 수 있는 길. 
// swanNQ는 현재 백조가 갈 수 없는 길, 하지만 하루가 지나면 갈 수 있는 길

// Q에는 이미 녹아있는 곳, Q의 주변 빙하를 녹여 NQ에 넣는다.
// NQ에는 내일 갈 수 있는 곳. 추후 Q = NQ하낟.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    visited.resize(n, vector<bool>(m, false));
    isFind = false;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != 'X') Q.push(make_pair(i, j));
            if(board[i][j] == 'L'){
                swan.first = i;
                swan.second = j;
            }
        }
    }
}

void solve()
{
    int day = 0;
    swanQ.push(swan);
    visited[swan.first][swan.second] = true;
    while(!isFind){
        swanBFS();
        if(isFind){
            cout << day;
            return;
        }
        waterBFS();
        Q = NQ;
        swanQ = swanNQ;
        while(!NQ.empty()) NQ.pop();
        while(!swanNQ.empty()) swanNQ.pop();
        day++;
    }
}

void swanBFS(){
    while(!swanQ.empty()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<= ny && ny < n && 0<=nx && nx<m){
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;

                if(board[ny][nx] == 'L'){
                    isFind = true;
                    return;
                }
                else if(board[ny][nx] == 'X'){
                    swanNQ.push(make_pair(ny, nx));
                }
                else if(board[ny][nx] == '.'){
                    swanQ.push(make_pair(ny, nx));
                }
            }
        }
    }
}

void waterBFS(){
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<= ny && ny < n && 0<=nx && nx<m){
                if(board[ny][nx] == 'X'){
                    board[ny][nx] = '.';
                    NQ.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}

