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
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int king, queen, rook, bishop, knight, pawn;
int k, q, r, b, kn, p;
void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    king = 1;
    queen = 1;
    rook = 2;
    bishop = 2;
    knight = 2;
    pawn = 8;
}

void input()
{
    cin >> k >> q >> r >> b >> kn >> p;
}

void solve()
{
    cout << king - k << ' ' << queen - q << ' ' << rook - r << ' ' << bishop - b << ' ' << knight - kn << ' ' << pawn - p << '\n';
}

int main()
{
    init();
    input();
    solve();
    return 0;
}