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
#define MAX 100001
/*
 #define CPP_INOUT true
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
*/
using namespace std;

void init();
void input();
void solve();
void dfs(int);

int n, t, cnt;
int tree[MAX]; // tree[i] = j, i가 고른 사람 J
bool visited[MAX];
bool done[MAX];

int main(){
    scanf("%d", &t);
    while(t--){
        init();
        input();
        solve();
    }
    return 0;
}

void init(){
    cnt = 0;
    memset(tree, 0, sizeof(tree));
    memset(visited, false, sizeof(visited));
    memset(done, false, sizeof(done));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &tree[i]);
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    printf("%d\n", n - cnt);
}

void dfs(int here)
{
    visited[here] = true;
    int next = tree[here];

    if(!visited[next])
    {
        dfs(next);
    }
    else if(!done[next])
    {
        for(int i=next; i!=here; i=tree[i])
        {
            cnt++;
        }
        cnt++;
    }
    done[here] = true;
}
