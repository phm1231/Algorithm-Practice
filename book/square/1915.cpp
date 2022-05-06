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

#define ll long long
#define MAX 1001
using namespace std;

void init();
void input();
void solve();

int n, m;
int board[MAX][MAX];
int dx[] = {-1, -1, 0};
int dy[] = {0, -1, -1};

void init()
{
    memset(board, 0, sizeof(board));
}

void input()
{
    scanf("%d %d", &n, &m);
    getchar();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char ch;
            scanf("%c", &ch);
            board[i][j] = ch - '0';
        }
        getchar();
    }
}

void solve()
{
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            int min_value = INT_MAX;
            for(int i=0; i<3; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                min_value = min(min_value, board[ny][nx]);
            }
            if(board[y][x] != 0){
                if(min_value > 0){
                    board[y][x] = min_value + 1;
                }
            }
        }
    }
    int res = INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            res = max(res, board[i][j]);
        }
    }
    printf("%d", res * res);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}