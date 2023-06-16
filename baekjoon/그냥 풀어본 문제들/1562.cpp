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
// dp[10][0] = 10자릿수이고, 0으로 끝나는 수면 1
// dp[i][0] = 숫자 개수가 i이고 0으로 끝나는 수의 개수
int dp[101][10] = {0, };
int n;

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    dp[10][0] = 1;
    for(int i=11; i<=n; i++){
        for(int j=0; j<10; j++){ // 끝자리
            if(j == 0) dp[i][j] = dp[i-1][1];
            else if(j == 9) dp[i][j] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    long long sum = 0;
    for(int i=0; i<10; i++){
        sum += dp[n][i];
    }
    cout << sum << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}