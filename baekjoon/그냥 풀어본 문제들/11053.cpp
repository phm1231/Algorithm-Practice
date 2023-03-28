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
int arr[1001] = {0, };
int dp[1001] = {0, };

void init()
{
    FAST
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
    int answer = -1;
    for(int i=0; i<n; i++){
        int value = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                value = max(dp[j], value + 1);
            }
        }
        dp[i] = value + 1;
        answer = max(answer, value);
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