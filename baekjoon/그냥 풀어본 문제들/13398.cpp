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

int n;
int arr[100000];
int dp[100000][2];

void init()
{
    FAST
    for(int i=0; i<100000; i++){
        arr[i] = 0;
        for(int j=0; j<2; j++){
            dp[i][j] = 0;
        }
    }
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void solve()
{
    int answer = arr[0];
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = arr[i];
        if (i == 0) continue;
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]); // dp[i][0]은 중간에 삭제하지 않았을 떄, arr[i]까지의 부분합 중 최댓값
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
        // dp[i][1]에서는, 삭제를 한 경우이다.
        // i 이전 위치에서 삭제를 했을 경우에 arr[i]는 무조건 포함되어야 하므로 dp[i-1][1] + arr[i]
        // i 위치를 삭제한 경우에 arr[i]는 사용되지 않으므로 dp[i-1][0]
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}