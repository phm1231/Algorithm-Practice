// based problem:
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

string from, to;
int fa, fb, ta, tb;
bool isFind = false;
unordered_map<string, bool> uom;

void dfs(int a, int b);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    fa = fb = ta = tb = 0;
}

void input()
{
    cin >> from >> to;
}

void solve()
{
    for(int i=0; i<from.size(); i++) from[i] == 'A' ? fa++ : fb++;
    for(int i=0; i<to.size(); i++) to[i] == 'A' ? ta++ : tb++;
    dfs(ta, tb);
    cout << isFind;
}


void dfs(int a, int b){
    uom[to] = true;
    if(a == fa && b == fb){
        if(from == to) isFind = true;
        return;
    }
    if(!isFind && a > fa && to.back() == 'A'){
        to.pop_back();
        if(!uom[to]) dfs(a-1, b);
        to += "A";
    }
    if(!isFind && b > fb && to.front() == 'B'){
        reverse(to.begin(), to.end());
        to.pop_back();
        if(!uom[to]) dfs(a, b-1);
        to += "B";
        reverse(to.begin(), to.end());
    }
}



int main()
{
    init();
    input();
    solve();
    return 0;
}