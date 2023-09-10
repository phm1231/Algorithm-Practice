#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, k;
vector<pair<int, int> > gems;
multiset<int> weights;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int m, v;
        cin >> m >> v;
        gems.push_back(make_pair(v, m)); // 가격, 무게
    }

    for(int i=0; i<k; i++){
        int w;
        cin >> w;
        weights.insert(w); // 가방에 담을 수 있는 최대 무게
    }
}

void solve()
{
    ll answer = 0;
    int cnt = 0; // 가방에 담은 보석 개수

    // 비싼 보석부터.
    sort(gems.begin(), gems.end(), [](const pair<int, int>& p, const pair<int, int>& q){
        return p.first > q.first;
    });

    for(int i=0; i<n; i++){
        if(cnt == k) break;

        int value = gems[i].first;
        int weight = gems[i].second;

        auto iter = weights.lower_bound(weight);
        if(iter == weights.end()) continue;

        weights.erase(iter);
        cnt++;
        answer += value;
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