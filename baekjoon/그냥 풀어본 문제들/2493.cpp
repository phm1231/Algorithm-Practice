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

int top[500002];
int dp[500002];
int siz;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    memset(top, 0, sizeof(top));
}

void input()
{
    cin >> siz;
    for(int i=1; i<=siz; i++){
        cin >> top[i];
    }
}

void solve()
{
    // dp[i] = i번째 탑이 보낸 신호를 수신하는 탑의 번호
    dp[0] = 0;
    dp[1] = 0; // 1번 탑은 받아줄 수 없음.

    for(int i=2; i<=siz; i++){
        // 바로 앞에 있는 top이 나보다 큼
        if(top[i-1] > top[i]){
            dp[i] = i-1;
        }

        else{
            int idx = i-1;
            while(1){
                int next_top = dp[idx]; // idx번 탑의 신호를 수신해주는 친구.
                if(next_top == 0){
                    dp[i] = 0;
                    break;
                }
                else if(top[next_top] > top[i]){
                    dp[i] = next_top;
                    break;
                }
                else{
                    idx = next_top;
                }
            }
        }
    }
    for(int i=1; i<=siz; i++){
        cout << dp[i] << ' ';
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}