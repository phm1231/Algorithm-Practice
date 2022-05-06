#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <cmath>

#define MAX 100001

using namespace std;

void init();
void input();
void solve();
pair<int, int> dfs(int, int);

int n, d;
vector< pair<int, int> > v[MAX]; // v[start].first = end, v[start].second = dist
bool visited[MAX];

void init(){
    memset(visited, false, sizeof(visited));
}

void input(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int start, end, dist;
        scanf("%d", &start);

        while(1){
            scanf("%d", &end);
            if(end == -1){
                break;
            }
            scanf("%d", &dist);
            v[start].push_back(make_pair(end, dist));
        }
    }
}

void solve(){
    visited[1] = true;
    pair<int, int> p = dfs(1, 0);
    memset(visited, false, sizeof(visited));
    
    visited[p.first] = true;
    pair<int, int> q = dfs(p.first, 0);
    printf("%d", q.second);
}

pair<int, int> dfs(int here, int dist_sum){
    int siz = v[here].size();
    pair<int, int> ret = make_pair(here, dist_sum); // first = 최종 목적지 노드, second = 거리
    pair<int, int> tmp;
    for(int i=0; i<siz; i++){
        int next = v[here][i].first;
        int dist = v[here][i].second;

        if(!visited[next]){
            visited[next] = true;
            tmp = dfs(next, dist_sum + dist);
            ret.second < tmp.second ? ret = tmp : ret = ret;
        }
    }
    return ret;
}

int main(){
    init();
    input();
    solve();
    return 0;
}