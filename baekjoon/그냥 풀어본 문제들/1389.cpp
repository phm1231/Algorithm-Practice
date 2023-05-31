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
void bfs(int);

int n, m;
int visited[101][101];

vector<vector<int> > path(101, vector<int>());

void bfs(int src){
    queue<int> q;
    queue<int> stageQ;

    for(int i=0; i<path[src].size(); i++){
        int dst = path[src][i];
        q.push(dst);
        stageQ.push(2);
        visited[src][dst] = 1;
    }

    while(!q.empty()){
        int here = q.front();
        int stage = stageQ.front();
        q.pop();
        stageQ.pop();

        for(int i=0; i<path[here].size(); i++){
            int next = path[here][i];
            if(visited[src][next] > stage){
                visited[src][next] = stage;
                q.push(next);
                stageQ.push(stage+1);
            }
        }
    }
}

void init()
{
    FAST
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            visited[i][j] = 987654321;
        }
        visited[i][i] = 0;
    }
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        path[src].push_back(dst);
        path[dst].push_back(src);
    }
}

void solve()
{
    for(int i=1; i<=n; i++){
        bfs(i);
    }

    int minValue = 987654321;
    int answer;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            sum+=visited[i][j];
        }
        if(minValue > sum){
            minValue = sum;
            answer = i;
        }
    }
    cout << answer << endl;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}