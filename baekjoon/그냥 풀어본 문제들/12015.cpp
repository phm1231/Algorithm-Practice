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
int sequence[1000000] = {0, };
vector<int> lis;


void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> sequence[i];
    lis.push_back(INT_MIN);
}

void solve()
{
    for(int i=0; i<n; i++){
        int target = sequence[i];
        if(lis.back() < target){
            lis.push_back(target);
        }
        else{
            auto iter = lower_bound(lis.begin(), lis.end(), target);
            *iter = target;
        }
    }
    cout << lis.size() - 1;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}