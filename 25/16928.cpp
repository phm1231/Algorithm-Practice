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
#include <set>
#include <unordered_map>

#define ll long long
#define MAX 101
using namespace std;

void init();
void input();
void solve();
void bfs();
void print();

int check(int here);
int visited[MAX];


unordered_map<int, int> snakes;
unordered_map<int, int> ladders;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1; i<MAX; i++) visited[i] = 987654321;
}

void input()
{
    int n, m;
    cin >> n >> m;
    // ladder
    for(int i=0; i<n; i++){
        int src, dst;
        cin >> src >> dst;
        ladders.insert(make_pair(src, dst));
    }
    // snake
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        snakes.insert(make_pair(src, dst));
    }

}

void solve()
{
    visited[1] = 1;
    bfs();
    cout << visited[100] << endl;
//    print();
}

void bfs(){
    queue<int> q;
    int start = 1;
    visited[start] = 0;
    q.push(start);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i=1; i<=6; i++){
            int next = here + i;
            if(next <= 100){
                if(next == 100){
                    visited[next] = visited[here] + 1;
                    return;
                }
                else{
                    if(visited[next] > visited[here] + 1){
                        visited[next] = visited[here] + 1;
                        int warf = check(next);
                        if(visited[warf] > visited[next]){
                            visited[warf] = visited[next];
                        }
                        q.push(warf);
                    }
                }
            }
        }
    }
}

void print(){
    for(int i=1; i<=100; i++){
        cout << visited[i] << ' ';
        if( i%10 == 0) cout << endl;
    }
}

int check(int here){
    unordered_map<int, int>::iterator uom;
    uom = ladders.find(here);
    if(uom != ladders.end()){
        return uom->second;
    }

    uom = snakes.find(here);
    if(uom != snakes.end()){
        return uom->second;
    }
    return here;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}