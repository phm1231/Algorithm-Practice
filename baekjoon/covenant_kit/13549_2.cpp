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

int n, k;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
}

void solve()
{
    if(n == k){
        cout << 0;
        return;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<bool> visited(100001, false);
    pq.push({0, n});
    visited[n] = true;

    while(!pq.empty()){
        int dist = pq.top().first;
        int here = pq.top().second;
        pq.pop();


        for(int next:{here*2, here+1, here-1}){
            if(next < 0 || next > 100000) continue;
            if(visited[next]) continue;

            if(next == here*2){
                if(next == k){
                    cout << dist;
                    return;
                }
                pq.push({dist, next});
                visited[next] = true;
            }
            else{
                if(next == k){
                    cout << dist + 1;
                    return;
                }
                pq.push({dist+1, next});
                visited[next] = true;
            }
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}