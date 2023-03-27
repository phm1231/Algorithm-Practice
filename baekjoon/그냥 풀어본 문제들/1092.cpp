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

int n, m;

vector<int> cranes;
vector<int> boxes;

void init()
{
    FAST
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        cranes.push_back(tmp);
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        boxes.push_back(tmp);
    }

    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());
}

void solve()
{
    if(boxes[0] > cranes[0]){
        cout << -1;
        return;
    }
    int cnt = 0;
    while(!boxes.empty()){
        cnt++;
        for(int i=0; i<cranes.size(); i++){
            for(int j=0; j<boxes.size(); j++){
                if(cranes[i] >= boxes[j]){
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }
    cout << cnt;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}