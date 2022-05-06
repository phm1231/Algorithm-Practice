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
#define MAX 101
// #define CPP_INOUT true

using namespace std;

void init();
void input();
void solve();

bool board[MAX][MAX];
int t, n;
int ileft[MAX];
int ibottom[MAX];

void init()
{
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
	memset(board, false, sizeof(board));
	memset(ileft, 0, sizeof(ileft));
	memset(ibottom, 0, sizeof(ibottom));
}

void input()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &ileft[i], &ibottom[i]);
	}
}

void solve()
{
	int area = 0;

	for(int i=0; i<n; i++)
	{
		int lx, ly, rx, ry;
		lx = ileft[i];
		rx = lx + 10;
		ly = 100 - ibottom[i] - 10;
		ry = ly + 10;

		for(int j=lx+1; j<=rx; j++)
		{
			for(int k=ly+1; k<=ry; k++)
			{
				board[j][k] = true;
			}
		}
	}
	
	for(int a=1; a<=100; a++)
	{
		for(int b=1; b<=100; b++)
		{
			if(board[a][b]) area++;
		}
	}
    printf("%d\n", area);
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
	    init();
  	    input();
  	    solve();
	}
   return 0;
}