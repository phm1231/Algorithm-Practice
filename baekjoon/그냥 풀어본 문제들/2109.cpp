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

int n, maxDay;
priority_queue<pair<int, int> > pq;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    maxDay = 0;
    for(int i=0; i<n; i++){
        int p, d;
        cin >> p >> d;
        maxDay = max(d, maxDay);
        pq.push(make_pair(p, d));
    }
}

void solve()
{

    vector<int> pays(10001, 0);
    // 급여 높은 순.
    while(!pq.empty()){
        int p = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        for(int i=d; i>=1; i--){
            if(pays[i] == 0){
                pays[i] = p;
                break;
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=maxDay; i++){
        answer += pays[i];
    }
    cout << answer;
    return;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}