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
using namespace std;

void init();
void input();
void solve();
bool isPromising();
void dfs(int, int);
int n;
int answer = 0;

bool board[16][16];

bool isPromising(int i, int j){
    int dy[] = {-1, -1, 1, 1};
    int dx[] = {1, -1, 1, -1};

    if(board[i][j]){ // 퀸이 있다면
        // 가로 검사
        for(int k=1; k<=n; k++)
            if(j != k && board[i][k]) return false;
        // 세로 검사
        for(int k=1; k<=n; k++)
            if(i != k && board[k][j]) return false;
        // 대각선 검사
        for(int k=0; k<4; k++){
            for(int w=1; w<=n; w++){
                int ny = i + dy[k]*w;
                int nx = j + dx[k]*w;
                if(1 <= ny && ny <= n && 1 <= nx && nx <= n){
                    if(ny != i && nx != j && board[ny][nx]) return false;
                }
            }
        }
    }

    return true;
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(board, false, sizeof(board));

}

void input()
{
    cin >> n;
}

void solve()
{
    for(int j=1; j<=n; j++){
        board[1][j] = true;
        dfs(1, j);
        board[1][j] = false;
    }
    cout << answer;
}

void dfs(int y, int x){
    if(isPromising(y, x)){
        if(y == n){
            answer++;
            return;
        }
        else{
            for(int j=1; j<=n; j++){
                if(j != x){
                    board[y+1][j] = true;
                    dfs(y+1, j);
                    board[y+1][j] = false;
                }
            }            
        }
    }
    return ;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}