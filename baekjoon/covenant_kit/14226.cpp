// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    // 붙여넣기는 배수만큼 늘어난다
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<bool> visited(2001, false);
    pq.push({0, 1});

    while(!pq.empty()){
        int dist = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(here == n){
            cout << dist;
            return;
        }

        if(visited[here]) continue;
        visited[here] = true;
        
        // 복사 후 붙여넣기 계속
        int copy = here;
        int idx = 2;
        for(int next=copy*2; next<=2000; next+=copy){
            if(!visited[next]){
                pq.push({dist + idx, next});
                idx++;
            }
        }
        // 삭제하기
        int next = here - 1;
        if(visited[next]) continue;
        if(next < 1) continue;
        else pq.push({dist + 1, next});
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}