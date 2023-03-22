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

int n;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n;
}

void solve()
{
    queue<int> q;
    long long dp[1000001];
    memset(dp, 0, sizeof(dp));

    if(0 <= n && n <= 10){
        cout << n;
        return;
    }
    if(n > 1022){
        cout << -1;
        return;
    }

    for(int i=1; i<10; i++){
        q.push(i);
        dp[i] = i;
    }

    int idx = 10;
    while(idx <= n && !q.empty()){
        long long number = q.front();
        q.pop();

        int last = number % 10;
        for(int i=0; i<last; i++){
            q.push(number * 10 + i);
            dp[idx++] = (number * 10 + i);
        }
    }
    if(idx >= n && dp[n] != 0) cout << dp[n];
    else cout << -1;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}