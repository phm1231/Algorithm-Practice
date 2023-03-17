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
using namespace std;

void init();
void input();
void solve();

string str;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> str;
}

void solve()
{
    stack<char> stk;
    int len = str.size();
    int push_cnt = len / 2 - 1;
    int next_idx;

    for(int i=0; i<=push_cnt; i++){
        stk.push(str[i]);
    }

    if(len % 2 != 0) next_idx = push_cnt + 2;
    else next_idx = push_cnt + 1;

    while(!stk.empty()){

        if(stk.top() == str[next_idx++]){
            stk.pop();
        }
        else{
            cout << "0";
            return;
        }
    }
    cout << "1";
}

int main()
{
    init();
    input();
    solve();
    return 0;
}