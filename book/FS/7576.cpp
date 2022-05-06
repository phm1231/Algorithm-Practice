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
#define MAX 1002
/*
 #define CPP_INOUT true
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
*/
using namespace std;

void init();
void input();
void solve();

int board[MAX][MAX];
int n, m;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

queue< pair<int, int> > q;

void init()
{
    memset(board, 0, sizeof(board));
}

void input()
{
    scanf("%d %d", &n, &m);

    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            board[i][j] = -1;
        }
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 1) q.push(make_pair(i, j));
        }
    }
}

void solve()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int i=0; i<4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if(board[next_x][next_y] == -1)
            {

            }
            else if( board[next_x][next_y] == 0 )
            {
                board[next_x][next_y] = board[x][y] + 1;
                q.push(make_pair(next_x, next_y));
            }
            else if(board[next_x][next_y] > board[x][y] + 1)
            {
                board[next_x][next_y] = board[x][y] + 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    int ans = INT_MIN;
    bool flag = true;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(board[i][j] == 0) flag = false;
            ans = max(ans, board[i][j]);
        }
    }
    flag ? printf("%d\n", ans - 1) : printf("-1");
}

int main()
{
    init();
    input();
    solve();
    return 0;
}