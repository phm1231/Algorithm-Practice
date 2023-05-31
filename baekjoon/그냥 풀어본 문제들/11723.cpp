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

int m;

void init()
{
    FAST
}

void input()
{
    cin >> m;
}

void solve()
{
    unordered_map<int, int> uom;
    unordered_map<int, int> uom_all;
    for(int i=1; i<=20; i++){
        uom_all[i] = 1;
    }

    while(m--){
        string cmd;
        int x;
        cin >> cmd;

        if(cmd == "add"){
            cin >> x;
            if(uom[x] == 1) continue;
            else uom[x]++;
        }
        else if(cmd == "remove"){
            cin >> x;
            if(uom[x] == 0) continue;
            else uom[x]--;
        }
        else if(cmd == "check"){
            cin >> x;
            if(uom[x] == 1) cout << "1\n";
            else cout << "0\n";
        }
        else if(cmd == "toggle"){
            cin >> x;
            if(uom[x] == 1) uom[x]--;
            else uom[x]++;
        }
        else if(cmd == "all"){
            uom = uom_all;
        }
        else if(cmd == "empty"){
            uom.clear();
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}