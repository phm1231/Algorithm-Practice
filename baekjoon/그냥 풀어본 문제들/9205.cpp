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
bool canGo(const pair<int, int>& from, const pair<int, int>& to);

int n; // 편의점의 개수
vector<pair<int, int> > locs; // [0] = 집, [1] = 페스티벌
bool dist[105][105]; // dist[i][j] = i에서 j로 가는 거리. 0은 집, 1~n = 편의점, n+1 = 축제

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    locs.clear();
    for(int i=0; i<105; i++){
        for(int j=0; j<105; j++){
            dist[i][j] = false;
        }
    }

    cin >> n;
    for(int i=0; i<n+2; i++){
        int y, x;
        cin >> y >> x;
        locs.push_back(make_pair(y, x));
    }


    for(int i=0; i<n+2; i++){
        for(int j=i+1; j<n+2; j++){
            dist[i][j] = dist[j][i] = canGo(locs[i], locs[j]);
        }
    }
}

void solve()
{
    vector<bool> visited(n+2, false);
    queue<int> q;
    q.push(0); // 집
    visited[0] = true;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        if(here == n+1){
            cout << "happy\n";
            return;
        }

        for(int next=0; next<n+2; next++){
            if(!visited[next] && dist[here][next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << "sad\n";
    return;

}

bool canGo(const pair<int, int>& from, const pair<int, int>& to){
    return (abs(from.first - to.first) + abs(from.second - to.second)) <= 1000;
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}