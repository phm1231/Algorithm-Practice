// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> v;
priority_queue<pair<int, int> > pq;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    v.clear();
    while(!pq.empty()) pq.pop();

    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
        pq.push(make_pair(v[i], i));
    }
}

void solve()
{
    long long answer = 0;

    for(int i=0; i<n; i++){
        // 과거나 현재의 가격이라면
        while(!pq.empty() && (pq.top().second <= i)) pq.pop();

        // 해당 주식을 비싸게 팔 수 있을 때, 사서 판다.
        if(v[i] < pq.top().first){
            answer += (pq.top().first - v[i]);
        }
    }
    cout << answer << "\n";
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}