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
#define MAX 102
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
void check();

int n;
bool board[MAX][MAX];
int island[MAX][MAX];
int number_island;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
queue< pair<int, int> > q;

void init()
{
    number_island = 0;
    memset(board, false, sizeof(board));
    memset(island, 0, sizeof(island));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if(tmp == 1)
            {
                board[i][j] = true;
                q.push(make_pair(i, j));
            }
            else
            {
                board[i][j] = false;
            }
        }
    }
}

void solve()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;

        if(board[x][y] && island[x][y] == 0)
        {
            number_island++;
            island[x][y] = number_island;
            stack< pair<int, int> > stk;
            stk.push(make_pair(x, y));
            while(!stk.empty())
            {
                pair<int, int> subpair = stk.top();
                stk.pop();
                int curx = subpair.first;
                int cury = subpair.second;

                for(int i=0; i<4; i++)
                {
                    int nx = curx + dx[i];
                    int ny = cury + dy[i];
                    if(board[nx][ny] && island[nx][ny] == 0)
                    {
                        island[nx][ny] = number_island;
                        stk.push(make_pair(nx, ny));
                    }
                }
            }
        }
        else
        {
            q.pop();
        }
    }
    // assign island number End.

    for(int i=1; i<=number_island; i++)
    {
        queue< pair<int, int> > bfsq;
        int mymap[MAX][MAX];
        for(int v=0; v<MAX; v++)
        {
            for(int b=0; b<MAX; b++)
            {
                mymap[v][b] = 99999;
            }
        }

        for(int a=1; a<=n; a++)
        {
            for(int b=1; b<=n; b++)
            {
                if(island[a][b] == i)
                {
                    bfsq.push(make_pair(a, b));
                    mymap[a][b] = 0;
                }
            }
        }

        while(!bfsq.empty())
        {
            pair<int, int> p = bfsq.front();
            bfsq.pop();
            int curx = p.first;
            int cury = p.second;
            for(int c=0; c<4; c++)
            {
                int nx = curx + dx[c];
                int ny = cury + dy[c];
                if(!board[nx][ny] && mymap[nx][ny] > mymap[curx][cury] + 1)
                {
                    mymap[nx][ny] = mymap[curx][cury] + 1;
                    bfsq.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void check()
{
    putchar('\n');
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", island[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    init();
    input();
    solve();
    return 0;
}