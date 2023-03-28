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
int sequence[1000] = {0, };
int dp[1000] = {0, };
vector<int> lis;


void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> sequence[i];
}

void solve()
{
    deque<int> dq;
    dq.push_front(sequence[0]);
    dp[0] = 1;

    for(int i=1; i<n; i++){
        int value = 0;
        for(int j=0; j<i; j++){
            if(sequence[i] > sequence[j]){
                value = max(dp[j], value);
            }
            else{

            }
        }
        dp[i] = value + 1;
        if(dp[i-1] < dp[i]){
            dq.push_back(sequence[i]);
        }
        else{
            if(sequence[i-1] > sequence[i]){
                dq.pop_back();
                dq.push_back(sequence[i]);
            }
        }
    }
    cout << dq.size() << endl;
    while(dq.size() > 1){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    cout << dq.front();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}