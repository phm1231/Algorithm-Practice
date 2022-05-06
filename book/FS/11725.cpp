#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int);

int n;
int root = 1;
vector<int> v[MAX]; // v[a] 는 b랑 연결되어 있다.
int parent[MAX];
bool visited[MAX];

void init(){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    parent[1] = 1;
}

void input(){
    int left, right;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &left, &right);
        v[left].push_back(right);
        v[right].push_back(left);
    }
}

void solve(){
    dfs(root);
    for(int i=2; i<=n; i++){
        printf("%d\n", parent[i]);
    }
}

void dfs(int par){
    int siz = v[par].size();
    for(int i=0; i<siz; i++){
        int next = v[par][i];
        if(!visited[next]){
            visited[next] = true;
            parent[next] = par;
            dfs(next);
        }
    }
}

int main(){

    init();
    input();
    solve();
    return 0;

}