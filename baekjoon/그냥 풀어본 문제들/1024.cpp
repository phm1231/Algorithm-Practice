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

int n, l; // n은 합, l은 길이

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n >> l;
}

void solve()
{
    for(int i=l; i<=100; i++){
        int t = (i*(i-1))/2;
        if((n-t) % i == 0 && (n-t)/i >= 0){
            int x = (n-t)/i;
            int sum = 0;
            for(int j=x; ; j++){
                sum += j;
                cout << j << " ";
                if(sum == n) break;
            }
            return;
        }
    }
    cout << -1;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}