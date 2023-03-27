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

int h, w;
int qc, kc, pc;

vector<pair<int, int> > qs;
vector<pair<int, int> > ks;
vector<pair<int, int> > ps;

int board[1001][1001];
// 0 = 안전하지 않은 칸
// 1 = 안전한 칸
// 2 = 폰
// 3 = 나이트
// 4 = 퀸
void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            board[i][j] = 1;
        }
    }
}

void input()
{
    cin >> h >> w;
    cin >> qc;
    for(int i=0; i<qc; i++){
        int y, x;
        cin >> y >> x;
        qs.push_back(make_pair(y, x));
        board[y][x] = 4;
    }
    cin >> kc;
    for(int i=0; i<kc; i++){
        int y, x;
        cin >> y >> x;
        ks.push_back(make_pair(y, x));
        board[y][x] = 3;

    }
    cin >> pc;
    for(int i=0; i<pc; i++){
        int y, x;
        cin >> y >> x;
        ps.push_back(make_pair(y, x));
        board[y][x] = 2;
    }
}

void solve()
{
    for(int i=0; i<qs.size(); i++){
        int y = qs[i].first;
        int x = qs[i].second;

        // y 고정, 가로
        for(int nx = x-1; nx>=1; nx--){
            if(board[y][nx] == 1 || board[y][nx] == 0) board[y][nx] = 0;
            else break;
        }
        for(int nx = x+1; nx<=w; nx++){
            if(board[y][nx] == 1 || board[y][nx] == 0) board[y][nx] = 0;
            else break;
        }

        // x 고정, 세로
        for(int ny=y-1; ny>=1; ny--){
            if(board[ny][x] == 1 || board[ny][x] == 0) board[ny][x] = 0;
            else break;
        }
        for(int ny=y+1; ny<=h; ny++){
            if(board[ny][x] == 1 || board[ny][x] == 0) board[ny][x] = 0;
            else break;
        }
        // 좌상
        int ny = y-1;
        int nx = x-1;
        while(ny >= 1 && nx >= 1){
            if(board[ny][nx] == 1 || board[ny][nx] == 0) board[ny][nx] = 0;
            else break;
            ny--;
            nx--;
        }
        // 좌하
        ny = y+1;
        nx = x-1;
        while(ny <= h && nx >= 1){
            if(board[ny][nx] == 1 || board[ny][nx] == 0) board[ny][nx] = 0;
            else break;
            ny++;
            nx--;
        }
        // 우상
        ny = y-1;
        nx = x+1;
        while(ny >= 1 && nx <= w){
            if(board[ny][nx] == 1 || board[ny][nx] == 0) board[ny][nx] = 0;
            else break;
            ny--;
            nx++;
        }
        // 우하
        ny = y+1;
        nx = x+1;
        while(ny <= h && nx <= w){
            if(board[ny][nx] == 1 || board[ny][nx] == 0) board[ny][nx] = 0;
            else break;
            ny++;
            nx++;
        }
    }

    // 나이트
    for(int i=0; i<ks.size(); i++){
        int wy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int wx[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        int y = ks[i].first;
        int x = ks[i].second;

        for(int j=0; j<8; j++){
            int ny = y + wy[j];
            int nx = x + wx[j];
            if(1 <= nx && nx <= w && 1 <= ny && ny <= h){
                if(board[ny][nx] == 0 || board[ny][nx] == 1) board[ny][nx] = 0;
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(board[i][j] == 1) cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}