// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int h, w;
vector<int> heights;
vector<vector<int> > board;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> h >> w;
    board.resize(h, vector<int>(w, 0)); // 0 = 빈공간, 1 = 벽, 2 = 물이 고임 
    heights.resize(w, 0);
    for(int i=0; i<w; i++){
        cin >> heights[i];
        for(int j=0; j<heights[i]; j++) board[i][j] = 1;
    }
}

void solve()
{
    int answer = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}