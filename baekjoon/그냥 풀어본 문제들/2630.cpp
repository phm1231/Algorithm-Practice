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
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();
bool check(int, int, int);
void recur(int, int, int);

int board[129][129];
int blue = 0;
int white = 0;
int n;

bool check(int y, int x, int siz){
    int color = board[y][x];
    for(int i=y; i<y+siz; i++){
        for(int j=x; j<x+siz; j++){
            if(color != board[i][j]){
                return false;
            }
        }
    }
    return true;
}

void recur(int y, int x, int siz){
    if(check(y, x, siz)){
        if(board[y][x] == 0) white++;
        else blue++;
    }
    else{
        recur(y, x, siz/2);
        recur(y+siz/2, x, siz/2);
        recur(y, x+siz/2, siz/2);
        recur(y+siz/2, x+siz/2, siz/2);
    }
}

void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    recur(0, 0, n);

    cout << white << "\n";
    cout << blue << "\n";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}