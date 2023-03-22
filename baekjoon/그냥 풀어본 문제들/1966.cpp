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
int check();

deque<int> dq;
int t, n, m;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> t;
}

void solve()
{
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        }

        int currentIdx = 0;
        int answer = 1;

        while(!dq.empty()){
            bool isPrint = dq.front() == check();
            if(isPrint && currentIdx == m){
                cout << answer << "\n";
                break;
            }
            else if(!isPrint && currentIdx == m){
                m += dq.size();
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else if(!isPrint){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else if(isPrint){
                dq.pop_front();
                answer++;                
            }
            currentIdx++;   
        }

        while(!dq.empty()) dq.pop_back();

    }
}

int check(){
    int ret = -1;
    for(int i=0; i<dq.size(); i++){
        ret = max(ret, dq[i]);
    }
    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}