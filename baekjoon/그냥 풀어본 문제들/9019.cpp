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
string bfs(int, int);

int D(int, int, int, int);
int S(int, int, int, int);
int L(int, int, int, int);
int R(int, int, int, int);
int getValue(int, int, int, int);
void setValue(int);

int d1, d2, d3, d4;
int n, m;
int visited[10001];

int t;
vector<string> cmds;

int getValue(int a1, int a2, int a3, int a4){
    return a4*1000 + a3*100 + a2*10 + a1;
}

void setValue(int num){
    d4 = num / 1000;
    d3 = (num % 1000) / 100;
    d2 = (num % 100) / 10;
    d1 = num % 10;
}

int D(int a1, int a2, int a3, int a4){
    int value = getValue(a1, a2, a3, a4);
    value = (value * 2) % 10000;
    return value;
}

int S(int a1, int a2, int a3, int a4){
    int value = getValue(a1, a2, a3, a4);
    if(value == 0) return 9999;
    else return value - 1;
}

int L(int a1, int a2, int a3, int a4){
    return getValue(a4, a1, a2, a3); 
}

int R(int a1, int a2, int a3, int a4){
    return getValue(a2, a3, a4, a1);
}

string bfs(int src, int dst){
    if(src == dst) return "";
    setValue(src);

    queue<int> q;
    queue<string> pathq;

    q.push(src);
    pathq.push(""); 
    visited[src] = true;

    while(!q.empty()){
        int number = q.front();
        q.pop();
        setValue(number);

        vector<int> v;
        v.push_back(D(d1, d2, d3, d4));
        v.push_back(S(d1, d2, d3, d4));
        v.push_back(L(d1, d2, d3, d4));
        v.push_back(R(d1, d2, d3, d4));

        for(int i=0; i<4; i++){
            if(!visited[v[i]]){
                visited[v[i]] = true;
                pathq.push(pathq.front() + cmds[i]);
                q.push(v[i]);
            }

            if(v[i] == dst){
                return pathq.front() + cmds[i];
            }
        }
        pathq.pop();
    }
    return "NO ANSWER";
}

void init()
{
    FAST
    cmds.push_back("D");
    cmds.push_back("S");
    cmds.push_back("L");
    cmds.push_back("R");
}

void input()
{
    cin >> n >> m;
}

void solve()
{
    // visited 초기화
    memset(visited, false, sizeof(visited));
    cout << bfs(n, m) << "\n";
}

int main()
{
    init();
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}