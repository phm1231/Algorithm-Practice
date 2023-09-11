#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, l, p;
vector<int> stations(1000001, 0);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int dist, oil;
        cin >> dist >> oil;
        stations[dist] = oil;
    }
    cin >> l >> p;
}

void solve()
{
    int cnt = 0;
    int here = 0; // 현재 위치
    int fuel = p;
    priority_queue<int> pq;

    while(here < l){
        if(stations[here] != 0) pq.push(stations[here]);
        if(fuel == 0){
            if(!pq.empty()){
                fuel += pq.top();
                pq.pop();
                cnt++;
            }
            else break;
        }
        here++;
        fuel--;
    }

    if(here == l) cout << cnt;
    else cout << -1;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}