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

int t, m, n, x, y;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b) / gcd(a, b);
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> m >> n >> x >> y;
}

void solve()
{
    int maxCount = lcm(m, n);
    int cnt = x;
    int tmpY= x;

    for(; cnt<=maxCount; cnt+=m){
        int ty = tmpY % n == 0 ? n : tmpY % n;

        if(ty == y){
            break;
        }
        tmpY = ty + m;
    }

    if(cnt > maxCount) cout << -1 << "\n";
    else cout << cnt << "\n";

}

int main()
{
    init();
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}