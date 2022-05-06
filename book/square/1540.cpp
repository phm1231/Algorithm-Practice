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

#define ll long long
#define MAX 51
using namespace std;

void init();
void input();
void solve();
void check();
int getGap(pair<int, int>, pair<int, int>);
void dfs(int, int, vector<int>);

int n;
bool visited[MAX];
int dist[MAX][MAX]; // dist[i][j] 는 i번째 점과 j번째 점 간의 거리
vector< pair<int, int> > v; // v[i]는 i번째 점의 x,y값
vector<int> ans; // 정사각형을 그리는데 성공했을 때, 그려진 정사각형 넓이

void init()
{
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
}

void input()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
}

void solve(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = getGap(v[i], v[j]);
        }
    }
    vector<int> tmp;
    dfs(0, 0, tmp);
    check();
}

void check(){
    int res = -1;
    int siz = ans.size();
    for(int i=0; i<siz; i++){
        res = max(ans[i], res);
    }
    printf("res: %d\n", res);
}

void dfs(int here, int d, vector<int> selected){
    visited[here] = true;
    int siz = selected.size();
    if(siz == 4 && dist[selected[0]][selected[3]] == d){
        ans.push_back(d);
        visited[here] = false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            selected.push_back(i);
            if(d == 0) dfs(i, dist[here][i], selected);
            else if(dist[here][i] == d) dfs(i, d, selected);

            selected.pop_back();
            if(d == 0) dfs(i, dist[here][i], selected);
            else if(dist[here][i] == d) dfs(i, d, selected);
        }
    }
    visited[here] = false;
}

int getGap(pair<int, int> p, pair<int, int> q){
    int x1 = p.first;
    int y1 = p.second;
    int x2 = q.first;
    int y2 = q.second;

    return (int)sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
}

int main()
{
    init();
    input();
    solve();
    return 0;
}