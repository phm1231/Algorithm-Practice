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
#define MAX 129
using namespace std;

void init();
void input();
void solve();
void dfs(int x, int y, int siz);

int n;
int board[MAX][MAX];
int black, white;

void init()
{
    black = white = 0;
    memset(board, 0, sizeof(board));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &board[i][j]);
        }
    }
}

void solve()
{
    dfs(1, 1, n);
    printf("%d\n%d\n", white, black);
}

void dfs(int x, int y, int siz){
    bool zero, one;
    zero = one = true;
    for(int i=x; i<x+siz; i++){
        for(int j=y; j<y+siz; j++){
            if(board[i][j] == 1) zero = false;
            if(board[i][j] == 0) one = false;
        }
    }

    if(zero) {white++; return;}
    if(one) {black++; return;}

    dfs(x, y, siz/2);
    dfs(x, y+siz/2, siz/2);
    dfs(x+siz/2, y, siz/2);
    dfs(x+siz/2, y+siz/2, siz/2);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}