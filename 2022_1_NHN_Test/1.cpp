// based problem: 아마 도형에 관한 문제
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
// #define CPP_INOUT true

using namespace std;

void init();
void input();
void solve();

int ix1, iy1;
int ix2, iy2;

void init()
{
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
}

void input()
{
	scanf("%d %d", &ix1, &iy1);
	scanf("%d %d", &ix2, &iy2);
}

void solve()
{
	int gapx, gapy;
	gapx = (ix1 - ix2) > 0 ? (ix1 - ix2) : (ix2 - ix1);
	gapy = (iy1 - iy2) > 0 ? (iy1 - iy2) : (iy2 - iy1);
	
	if( gapx == 0 && gapy == 0)
	{
		printf("DOT\n");		
	}
	else if( (gapx == 0 && gapy != 0) || (gapx != 0 && gapy == 0) )
	{
		printf("SEGMENT");
	}
	else if(gapx == gapy)
	{
		printf("SQUARE");
	}
	else
	{
		printf("RECTANGLE");
	}
}

int main()
{
    init();
    input();
    solve();
    return 0;
}