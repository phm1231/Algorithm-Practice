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

int t;
int n;
void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    map<int, int> m;
    while(n--){
        string cmd_str, i_str;
        cin >> cmd_str >> i_str;
        char cmd = cmd_str[0];
        int x = stoi(i_str);

        if(cmd == 'D' && !m.empty()){
            // 최댓값 제거
            if(x == 1){
                map<int, int>::iterator iter = m.end();
                iter--;
                int maxValue = iter->first;
                if(iter->second == 1) m.erase(iter);
                else m[maxValue]--;
            }
            // 최솟값 제거
            else if(x == -1){
                map<int, int>::iterator iter = m.begin();
                int minValue = iter->first;
                if(iter->second == 1) m.erase(iter);
                else m[minValue]--;
            }
        }
        else if(cmd == 'I'){
            m[x]++;
        }
    }

    if(m.empty()){
        cout << "EMPTY\n";
    }
    else{
        map<int, int>::iterator iter = m.end();
        iter--;
        cout << iter->first << ' ' << m.begin()->first << "\n";
    }
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