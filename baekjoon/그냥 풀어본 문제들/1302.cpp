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

map<string, int> m;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    int cnt;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        string str;
        cin >> str;
        m[str]++;
    }
}

void solve()
{
    string answer_k;
    int answer_v = -1;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        string k = iter->first;
        int v = iter->second;

        if(answer_v < v){
            answer_v = v;
            answer_k = k;
        }
        else if(answer_v == v){
            if(answer_k > k) answer_k = k;
        }
    }
    cout << answer_k;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}