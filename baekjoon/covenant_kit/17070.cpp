// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define ll long long
#define MAX 100001
// 0이면 빈칸이고 1이면 벽이다.

void init();
void input();
void solve();
bool canGoDiagonal(int, int);
bool canGoRight(int, int);
bool canGoDown(int, int);

int n;
vector<vector<int> > board(17, vector<int>(17, 0));
vector<vector<int> > dp(17, vector<int>(17, 0));

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    // 처음에는 (1,1) (1,2)에 가로로 놓여있다.
    queue<pair<int, int> > Q;
    queue<int> dirQ; // 0이면 가로, 1이면 세로, 2이면 대각선
    Q.push({1, 2});
    dirQ.push(0);

    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        int dir = dirQ.front();
        dp[y][x]++;
        Q.pop();
        dirQ.pop();

        // 가로로 놓여져있다면
        if(dir == 0){
            // 가로
            bool canRight = canGoRight(y, x);
            if(canRight){
                dirQ.push(0);
                Q.push({y, x+1});
            }
            // 대각선
            bool canDiago = canGoDiagonal(y, x);
            if(canDiago){
                dirQ.push(2);
                Q.push({y+1, x+1});
            }
        }
        // 세로로 놓여져 있다면
        else if(dir == 1){
            // 세로
            bool canDown = canGoDown(y, x);
            if(canDown){
                dirQ.push(1);
                Q.push({y+1, x});
            }
            // 대각선
            bool canDiago = canGoDiagonal(y, x);
            if(canDiago){
                dirQ.push(2);
                Q.push({y+1, x+1});
            }
        }
        // 대각선으로 놓여져 있다면
        else if(dir == 2){
            // 가로
            bool canRight = canGoRight(y, x);
            if(canRight){
                dirQ.push(0);
                Q.push({y, x+1});
            }
            // 세로
            bool canDown = canGoDown(y, x);
            if(canDown){
                dirQ.push(1);
                Q.push({y+1, x});
            }
            // 대각선
            bool canDiago = canGoDiagonal(y, x);
            if(canDiago){
                dirQ.push(2);
                Q.push({y+1, x+1});
            }
        }
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    */
    cout << dp[n][n];
}


bool canGoDiagonal(int y, int x){
    if(y + 1 <= n && x + 1 <= n){
        if(board[y+1][x] == 0 && board[y+1][x+1] == 0 && board[y][x+1] == 0) return true;
    }
    return false;
}

bool canGoRight(int y, int x){
    if(x+1 <= n && board[y][x+1] == 0) return true;
    return false;
}

bool canGoDown(int y, int x){
    if(y+1 <= n && board[y+1][x] == 0) return true;
    return false;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}