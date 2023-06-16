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
void recursive(int, int, int);
bool isSearched = false;
int n, r, c;
int answer = 0;
int cnt = 0;

void recursive(int y, int x, int siz){
    if(isSearched) return;

    if(y <= r && r < y+siz && x <= c && c < x + siz){
        if(siz == 2){
            if( y <= r && r < y+2 && x <= c && c < x+2){
                for(int i=y; i<y+2; i++){
                    for(int j=x; j<x+2; j++){
                        if( i == r && j == c){
                            answer = cnt;
                            isSearched = true;
                        }
                        cnt++;
                    }
                }
            }
        }
        else{
            recursive(y, x, siz/2);
            recursive(y, x+siz/2, siz/2);
            recursive(y+siz/2, x, siz/2);
            recursive(y+siz/2, x+siz/2, siz/2);
        }
    }
    else{
        cnt += (siz*siz);
    }
}

void init()
{
    FAST
}

void input()
{
    cin >> n >> r >> c;
}

void solve()
{
    int number = 2;
    for(int i=2; i<=n; i++) number*=2;
    recursive(0, 0, number);
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}