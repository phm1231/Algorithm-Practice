// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<pair<int, int> > v;
vector<int> days(200000, 0);
vector<int> duplication(200000, 0);

// 데드라인 기준으로 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int deadline, cnt;
        cin >> deadline >> cnt;
        v.push_back(make_pair(deadline, cnt));
    }
}

void solve()
{
    sort(v.begin(), v.end());

    // 컵라면 개수대로 정렬
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        int deadline = v[i].first;
        int cnt = v[i].second;
    
        if(pq.size() < deadline){
            pq.push(cnt);
        }
        else{
            if(pq.top() < cnt){
                pq.pop();
                pq.push(cnt);
            }
        }
    }
    ll answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}