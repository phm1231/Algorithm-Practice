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
#define MAX 101
using namespace std;

void init();
void input();
void solve();

int n, max_weight;
int weights[MAX];
int values[MAX];
int dp[MAX][100001];

void init()
{
    memset(weights, 0, sizeof(weights));
    memset(values, 0, sizeof(values));
    memset(dp, 0, sizeof(dp));
}

void input()
{
    scanf("%d %d", &n, &max_weight);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &weights[i], &values[i]);
    }

}

void solve()
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=max_weight; j++){
            if(j - weights[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d", dp[n][max_weight]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}