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

int n, m;
int arr[51][51];
bool board[51][51];

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(arr, 0, sizeof(arr));
    memset(board, true, sizeof(board));
}

void input()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int d;
            scanf("%1d", &d);
            if(d != arr[i][j]) board[i][j] = false;
        }
    }
}

void solve()
{
    int cnt = 0;
    if(n < 3 || m < 3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!board[i][j]){
                    cout << -1;
                    return;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(board[i][j]) continue;

            if(i < n-2 && j < m-2){
                for(int y=i; y<i+3; y++){
                    for(int x=j; x<j+3; x++){
                        board[y][x] = !board[y][x];
                    }
                }
                cnt++;
            }
            else{
                if(!board[i][j]){
                    cout << -1;
                    return;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!board[i][j]){
                cout << -1;
                return;
            }
        }
    }
    cout << cnt;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}